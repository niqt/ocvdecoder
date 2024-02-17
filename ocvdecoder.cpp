#include "ocvdecoder.h"
#include <opencv2/opencv.hpp>
#include <QUrl>
#include <QtConcurrent/QtConcurrent>

using namespace std;

OCVDecoder::OCVDecoder(QObject *parent): QObject(parent)
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);

    m_detector = makePtr<wechat_qrcode::WeChatQRCode>("" , "" ,
                                                      "", "");
}

void OCVDecoder::setFrame(const QVideoFrame &frame)
{
    if (m_run && !isDecoding() && m_processThread.isFinished()) {
        qDebug() << "DECODING1\n";
        m_decoding = true;
        QImage image = frame.toImage().convertToFormat(QImage::Format_RGB32).rgbSwapped();

        m_processThread = QtConcurrent::run([=]() {
            qDebug() << "DECODING2\n";
            if(image.isNull()) {
                m_decoding = false;
                return;
            }

            cv::Mat img(image.height(), image.width(), CV_8UC4, (void *) image.bits(), image.bytesPerLine());
            vector<Mat> points;
            auto res = m_detector->detectAndDecode(img, points);
            if (res.size() > 0) {
                for (const auto& value : res) {
                    qDebug() << " opencv " << QString(value.c_str());
                    emit decoded(QString(value.c_str()));
                    m_run = false;
                    break;
                }
            }
            m_decoding = false;
        });
    }

}

void OCVDecoder::setVideoSink(QObject *videoSync)
{
    m_videoSink = qobject_cast<QVideoSink*>(videoSync);

    if (m_videoSink) {
        QObject::connect(m_videoSink, &QVideoSink::videoFrameChanged,
                         this, &OCVDecoder::setFrame);
    }
}

void OCVDecoder::setRun(bool run)
{
    m_run = run;
}

// https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap/

static cv::Mat QImageToCvMat(QImage inImage, bool inCloneImageData = true)
{
    switch ( inImage.format() )
    {
    // 8-bit, 4 channel
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
    {
        cv::Mat  mat( inImage.height(), inImage.width(),
                      CV_8UC4,
                      const_cast<uchar*>(inImage.bits()),
                      static_cast<size_t>(inImage.bytesPerLine())
                      );

        return (inCloneImageData ? mat.clone() : mat);
    }

        // 8-bit, 3 channel
    case QImage::Format_RGB32:
    {
        if ( !inCloneImageData ) {
            qWarning() << "QImageToCvMat() - Conversion requires cloning so we don't modify the original QImage data";
        }

        cv::Mat  mat( inImage.height(), inImage.width(),
                      CV_8UC4,
                      const_cast<uchar*>(inImage.bits()),
                      static_cast<size_t>(inImage.bytesPerLine())
                      );

        cv::Mat  matNoAlpha;

        cv::cvtColor( mat, matNoAlpha, cv::COLOR_BGRA2BGR );   // drop the all-white alpha channel

        return matNoAlpha;
    }

        // 8-bit, 3 channel
    case QImage::Format_RGB888:
    {
        if ( !inCloneImageData ) {
            qWarning() << "QImageToCvMat() - Conversion requires cloning so we don't modify the original QImage data";
        }

        QImage   swapped = inImage.rgbSwapped();

        cv::Mat mat( swapped.height(), swapped.width(),
                        CV_8UC3,
                        const_cast<uchar*>(swapped.bits()),
                        static_cast<size_t>(swapped.bytesPerLine())
                        );
       return (inCloneImageData ? mat.clone() : mat);
    }

        // 8-bit, 1 channel
    case QImage::Format_Grayscale8:
    case QImage::Format_Indexed8:
    {
        cv::Mat  mat( inImage.height(), inImage.width(),
                      CV_8UC1,
                      const_cast<uchar*>(inImage.bits()),
                      static_cast<size_t>(inImage.bytesPerLine())
                      );

        return (inCloneImageData ? mat.clone() : mat);
    }


#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)
    case QImage::Format_Grayscale16:
    {
        cv::Mat mat(cv::Size(inImage.width(),inImage.height()),CV_16U,const_cast<uchar*>(inImage.bits()),cv::Mat::AUTO_STEP);
        return (inCloneImageData ? mat.clone() : mat);
    }
#endif

    default:
        qWarning() << "QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
        break;
    }

    return cv::Mat();
}

OCVDecoder::~OCVDecoder()
{
    if(!m_processThread.isFinished()) {
        m_processThread.cancel();
        m_processThread.waitForFinished();
    }
    if (m_detector) {
        delete m_detector;
    }
}
