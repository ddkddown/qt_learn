import QtQuick 2.12
import QtQuick.Window 2.12
import an.qt.ImageProcessor 1.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.1
import QtQuick.Controls.Styles 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rect;
        width: 640;
        height: 480;
        color: "#121212";

        onWidthChanged: {
            console.log("fuck! width changed!", width)
        }

        BusyIndicator {
            id: busy;
            running: false;
            anchors.centerIn: parent;
            z: 2;
        }

        Label {
            id: stateLabel;
            visible: false;
            anchors.centerIn: parent;
        }

        Image {
            objectName: "imageViewer";
            id: imageViewer;
            asynchronous: true;
            anchors.fill: parent;
            fillMode: Image.PreserveAspectFit;
            onStatusChanged: {
                if(imageViewer.status == Image.Loading) {
                    busy.running = true;
                    stateLabel.visible = false;
                } else if (imageViewer.status == Image.Ready) {
                    busy.running = false;
                } else if (imageViewer.status == Image.Error) {
                    busy.running = false;
                    stateLabel.visible = true;
                    stateLabel.text = "ERROR";
                }
            }
        }

        ImageProcessor {
            id: processor;
            onFinished: {
                imageViewer.source = "/home/ddk/Downloads/17-45-41-D7yOqPjUcAAEmrA.jpg"
            }
        }

        Button {
            anchors.centerIn: parent;
            onClicked: {
                rect.width = rect.width*2;
            }
        }


    }
}
