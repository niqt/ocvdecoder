import Felgo
import QtQuick
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtMultimedia
import ocvdecoder

App {
    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    NavigationStack {

        AppPage {
            title: qsTr("Main Page")
            id: pg
            Camera
                {
                    id:camera
                    active: true
                    //focusMode: Camera.FocusModeAuto
                }

                CaptureSession {
                    camera: camera
                    videoOutput: videoOutput
                }

                VideoOutput
                {
                    id: videoOutput
                    /*anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right*/
                   //fillMode: VideoOutput.Stretch
                    anchors.fill: parent

                    property double captureRectStartFactorX: 0.25
                    property double captureRectStartFactorY: 0.25
                    property double captureRectFactorWidth: 0.5
                    property double captureRectFactorHeight: 0.5

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            camera.customFocusPoint = Qt.point(mouseX / width,  mouseY / height);
                            camera.focusMode = Camera.FocusModeManual;
                        }
                    }

                    Rectangle {
                        id: captureZone
                        color: "red"
                        opacity: 0.2
                        width: parent.width * parent.captureRectFactorWidth
                        height: parent.height * parent.captureRectFactorHeight
                        x: parent.width * parent.captureRectStartFactorX
                        y: parent.height * parent.captureRectStartFactorY
                    }

                     Component.onCompleted: { camera.active = false; camera.active = true; }
                }
                OCVDecoder {
                    videoSink: videoOutput.videoSink
                }

        }

    }
}
