import QtQuick 2.2

Rectangle {
    width: 300;
    height: 200;
    color: "#c0c0c0";
    focus: true;
    Keys.enabled: true;
    Keys.onBackPressed: Qt.quit();
    Keys.onEscapePressed: Qt.quit();

    Text {
        id: keyView;
        text: qsTr("text");
        anchors.centerIn: parent;
    }
}