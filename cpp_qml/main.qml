import QtQuick 2.12
import QtQuick.Window 2.12
//import qt.ColorMaker 1.0
import QtQuick.Controls 2.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: 360;
        height: 360;
        Text {
            id: timeLabel;
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            font.pixelSize: 26;
        }

        /*ColorMaker {
            id: colorMaker;
            color: Qt.green;
        }*/

        Rectangle {
            id: colorRect;
            anchors.centerIn: parent;
            width: 200;
            height: 200;
            color: "blue";
        }

        Button {
            id: start;
            text: "start";
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            onClicked: {
                colorMaker2.start();
            }
        }

        Button {
            id: stop;
            text: "stop";
            anchors.left: start.right;
            anchors.leftMargin: 4;
            anchors.bottom: start.bottom;
            onClicked: {
                colorMaker2.stop();
            }
        }

        anchors.leftMargin: 20

        Text {
            id: test
            text: colorMaker2.getInt()
        }
    }
}
