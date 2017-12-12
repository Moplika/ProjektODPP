import QtQuick 2.4
import QtQuick.Controls 1.4

Item {
    width: 800
    height: 560

    ListModel {
        id: testModel
        ListElement {
            recordId: "1"
            clientId: "4562189"
            clientName: "Specjalna firma pana Kowalskiego"
        }
        ListElement {
            recordId: "2"
            clientId: "12345678"
            clientName: "SSO Obuwie Tenisowe"
        }
        ListElement {
            recordId: "3"
            clientId: "172351"
            clientName: "Tchibo"
        }
    }

    TableView {
        id: tableView
        anchors.fill: parent
        TableViewColumn {
            role: "recordId"
            title: "Lp"
            width: 50
        }
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
        model: testModel
    }
}
