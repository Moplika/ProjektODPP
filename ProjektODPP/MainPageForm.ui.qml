import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Item {
    width: 800
    height: 600
    property alias buttonBar: buttonBar

    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent

        ButtonBar {
            id: buttonBar
            height: 40
            Layout.fillWidth: true
            Layout.fillHeight: false
            Layout.preferredHeight: 40
        }

        TabView {
            id: tabView
            height: 500
            Layout.fillHeight: true
            tabsVisible: true
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

            Tab {
                id: newClient
                enabled: true
                smooth: false
                antialiasing: false
                asynchronous: false
                title: "Dodaj zadanie"
                source: "NewClient.qml"
            }

            Tab {
                id: allTasks
                title: "Wszystkie zadania"
                source: "AllTasks.qml"
            }

            Tab {
                id: schedule
                anchors.right: newClient.left
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.rightMargin: 0
                title: "Harmonogram"
                source: "Schedule.qml"
            }
        }
    }
}
