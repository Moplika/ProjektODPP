import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 800
    height: 640

    RowLayout {
        id: rowLayout
        spacing: 5
        anchors.fill: parent

        Label {
            id: label
            width: 300
            text: qsTr("Ostatni harmonogram wyznaczono ...")
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.preferredWidth: -1
            Layout.fillHeight: true
            font.pointSize: 12
            wrapMode: Text.WordWrap
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: button
            width: 150
            text: qsTr("Wyznacz harmonogram")
            Layout.fillHeight: false
            Layout.preferredWidth: 130
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            id: button1
            text: qsTr("Zaparz kawę")
            Layout.preferredWidth: 130
            Layout.fillHeight: false
        }

        Button {
            id: button2
            text: qsTr("Zrób cos jeszcze")
            Layout.preferredWidth: 130
            Layout.fillHeight: false
        }
    }
}
