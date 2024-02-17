#ifndef OCVDECODER_H
#define OCVDECODER_H

#include <QObject>
#include <QtMultimedia/QVideoSink>
#include <QtMultimedia/QVideoFrame>
#include "opencv2/wechat_qrcode.hpp"
#include <qqml.h>
#include <QFuture>

using namespace cv;

class OCVDecoder: public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QObject* videoSink WRITE setVideoSink)
    Q_PROPERTY(bool run READ run WRITE setRun)
public:
    OCVDecoder(QObject *parent = nullptr);
    ~OCVDecoder();
    void setVideoSink(QObject *videoSink);
    bool isDecoding() {return m_decoding; }
    bool run() {return m_run;}
    void setRun(bool run);

public slots:
    void setFrame(const QVideoFrame &frame);


signals:
    void videoSyncChnaged();
    void decoded(const QString &qr);

private:
    QVideoSink *m_videoSink;
    Ptr<wechat_qrcode::WeChatQRCode> m_detector;
    QFuture<void> m_processThread;
    bool m_decoding;
    bool m_run;
};

#endif // OCVDECODER_H
