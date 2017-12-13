import QtQuick 2.4
import QtQuick.Controls 1.4

Item {
    width: 800
    height: 560

    ListModel {
        id: testScheduleModel
        ListElement {
            orderId: "1"
            clientId: "121587"
            clientName: "Kowalski & Spolka"
            stageId: "1"
            teamId: "1"
            executionTime: "25"
            startTime: ""
            endTime: ""
        }
    }


    TableView {
        id: tableView
        anchors.fill: parent
        TableViewColumn {
            role: "clientId"
            title: "Numer klienta"
            width: 100
        }
        TableViewColumn {
            role: "clientName"
            title: "Nazwa klienta"
            width: 200
        }
        TableViewColumn {
            role: "stageId"
            title: "Nr etapu"
            width: 100
        }
        TableViewColumn {
            role: "teamId"
            title: "Nr ekipy"
            width: 100
        }
        TableViewColumn {
            role: "executionTime"
            title: "Czas wykonania"
            width: 100
        }
        TableViewColumn {
            role: "startTime"
            title: "Czas rozpoczęcia"
            width: 100
        }
        TableViewColumn {
            role: "endTime"
            title: "Czas zakończenia"
            width: 100
        }

        model: testScheduleModel
    }
}
