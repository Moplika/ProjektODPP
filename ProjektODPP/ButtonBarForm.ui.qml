import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 800
    height: 640
    property alias btn_saveSchedule: btn_saveSchedule
    property alias btn_findSchedule: btn_findSchedule
    property alias label_lastSchedule: label_lastSchedule

    RowLayout {
        id: rowLayout
        spacing: 5
        anchors.fill: parent

        Label {
            id: label_lastSchedule
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
            id: btn_findSchedule
            width: 150
            text: qsTr("Wyznacz harmonogram")
            Layout.fillHeight: false
            Layout.preferredWidth: 130
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            id: btn_saveSchedule
            text: qsTr("Zapisz wyniki")
            Layout.preferredWidth: 130
            Layout.fillHeight: false
        }
    }
}
