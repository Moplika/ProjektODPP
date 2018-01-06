import QtQuick 2.1
import QtQuick.Controls 1.0

Item {
    width: 1920
    height: 1080
    anchors.fill: parent


    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent
    }
    Image {
        id: image
        fillMode: Image.PreserveAspectFit
        anchors.rightMargin: 17
        anchors.bottomMargin: -71
        anchors.leftMargin: -20
        anchors.topMargin: 71
        anchors.fill: parent
        source: "resources/logo.png"
    }
}
