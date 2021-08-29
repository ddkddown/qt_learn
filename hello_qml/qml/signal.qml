import QtQuick 2.2
import QtQuick.Controls 2.1

Rectangle {
    width: 320;
    height: 480;

    Button {
        id: quit;
        text: "quit";
        anchors.left: parent.left;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4;
        onClicked: {
            Qt.quit();
        }
    }
}