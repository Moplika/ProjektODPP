import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Item {
    width: 800
    height: 560

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
                title: "Harmonogram"
                source: "Schedule.qml"
            }
        }
    }
}
