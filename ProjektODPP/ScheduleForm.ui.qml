import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2

Item {
    id: window
    width: 800
    height: 560
    property alias label_cmax: label_cmax
    property alias btn_refresh: btn_refresh
    property alias tableView_schedule: tableView_schedule
    property alias scheduleModel: scheduleModel

    property int widthUnit: window.width/17

    Rectangle {
        id: background
        color: "#ffffff"
        anchors.fill: parent
    }

    ListModel {
        id: scheduleModel
//        ListElement {
//            recordId: "1"
//            clientId: "121587"
//            clientName: "Kowalski & Spolka"
//            stageId: "1"
//            teamId: "1"
//            executionTime: "25"
//            startTime: ""
//            endTime: ""
//        }
    }



    Button {
        id: btn_refresh
        height: 30
        text: qsTr("Odśwież")
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
    }

    Label {
        id: label
        x: 10
        y: 5
        width: 80
        height: 30
        text: qsTr("Całkowity czas: ")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }

    Label {
        id: label_cmax
        x: 95
        y: 5
        width: 47
        height: 30
        text: qsTr("123456")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
    }

    TableView {
        id: tableView_schedule
        sortIndicatorColumn: 1
        sortIndicatorOrder: 0
        alternatingRowColors: true
        frameVisible: true
        highlightOnFocus: false
        headerVisible: true
        backgroundVisible: true
        verticalScrollBarPolicy: -1
        sortIndicatorVisible: true
        anchors.top: btn_refresh.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 5
        TableViewColumn {
            role: "recordId"
            title: "Lp"
            width: widthUnit
        }
        TableViewColumn {
            role: "clientId"
            title: "Numer klienta"
            width: 2*widthUnit
        }
        TableViewColumn {
            role: "clientName"
            title: "Nazwa klienta"
            width: 4*widthUnit
        }
        TableViewColumn {
            role: "stageId"
            title: "Nr etapu"
            width: 2*widthUnit
        }
        TableViewColumn {
            role: "teamId"
            title: "Nr ekipy"
            width: 2*widthUnit
        }
        TableViewColumn {
            role: "executionTime"
            title: "Czas wykonania"
            width: 2*widthUnit
        }
        TableViewColumn {
            role: "startTime"
            title: "Czas rozpoczęcia"
            width: 2*widthUnit
        }
        TableViewColumn {
            role: "endTime"
            title: "Czas zakończenia"
            width: 2*widthUnit
        }

        model: scheduleModel
    }






}
