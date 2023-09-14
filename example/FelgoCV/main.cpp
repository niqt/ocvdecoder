#include <QApplication>
#include <FelgoApplication>

#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include <QQmlApplicationEngine>
#include <iostream>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/wechat_qrcode.hpp>

using namespace std;
using namespace cv;
using namespace std::chrono;
// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>
using namespace cv;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FelgoApplication felgo;

    QQmlApplicationEngine engine;
    felgo.initialize(&engine);

    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    // use this during development
    // for PUBLISHING, use the entry point below
    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    //felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);


    /*GraphicalCodeDetector qrcode = QRCodeDetector();
    std::vector<Point> corners;

    Mat input = imread(QUrl::fromLocalFile("./assets/qr.png").toLocalFile().toStdString(), IMREAD_COLOR);
    String decode_info1 = qrcode.detectAndDecode(input, corners);

    qDebug() << decode_info1.c_str();*/


   /* cv::Mat pts, result;
    std::string qrData = qrCode.detectAndDecode(img, pts, result);

    std::cout<< qrData<<std::endl;*/

    /* good
    Ptr<wechat_qrcode::WeChatQRCode> detector;
    detector = makePtr<wechat_qrcode::WeChatQRCode>("", "", "", "");


    Mat img = imread(QUrl::fromLocalFile("./assets/qr.png").toLocalFile().toStdString(), IMREAD_COLOR);
          // Declare vector 'points' to store bounding box coordinates.
      vector<Mat> points;
      // Start time.
      auto start = high_resolution_clock::now();
      // Detect and decode.
      auto res = detector->detectAndDecode(img, points);
      // End time.
      auto stop = high_resolution_clock::now();
      // Time taken in milliseconds.
      //auto duration = duration_cast<milliseconds>(stop - start);
          // If detected.
      if (res.size() > 0)
      {
        // Print detected data.
        for (const auto& value : res)
        {
          cout << value << endl;
        }
        // Iterate through the vector and convert to Mat. Required,
                // as we need to access the elements while drawing the box.

      }
    */

    return app.exec();
}
