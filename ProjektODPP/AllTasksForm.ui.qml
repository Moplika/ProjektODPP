import QtQuick 2.4
import QtQuick.Controls 1.4

Item {
    width: 800
    height: 560

    ListModel {
        id: testScheduleModel
        ListElement {
            recordId: "1"
            clientId: "121587"
            clientName: "Kowalski & Spolka"
            stage1Time: "25"
            stage2Time: "147"
            stage3Time: "85"
            stage4Time: "12"
        }
        ListElement {
            recordId: "2"
            clientId: "134597"
            clientName: "Abracadabra"
            stage1Time: "67"
            stage2Time: "32"
            stage3Time: "54"
            stage4Time: "54"
        }
        ListElement {
            recordId: "3"
            clientId: "145673"
            clientName: "Alkohole Świata"
            stage1Time: "145"
            stage2Time: "75"
            stage3Time: "24"
            stage4Time: "74"
        }
        ListElement {
            recordId: "4"
            clientId: "123789"
            clientName: "Pojemniki i swieczki"
            stage1Time: "23"
            stage2Time: "785"
            stage3Time: "45"
            stage4Time: "120"
        }
        ListElement {
            recordId: "5"
            clientId: "215493"
            clientName: "Domy Nowaka"
            stage1Time: "20"
            stage2Time: "58"
            stage3Time: "13"
            stage4Time: "24"
        }
        ListElement {
            recordId: "6"
            clientId: "215493"
            clientName: "Domy Nowaka"
            stage1Time: "87"
            stage2Time: "123"
            stage3Time: "64"
            stage4Time: "54"
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
        TableViewColumn {
            role: "stage1Time"
            title: "Czas etapu 1"
            width: 100
        }
        TableViewColumn {
            role: "stage2Time"
            title: "Czas etapu 2"
            width: 100
        }
        TableViewColumn {
            role: "stage3Time"
            title: "Czas etapu 3"
            width: 100
        }
        TableViewColumn {
            role: "stage4Time"
            title: "Czas etapu 4"
            width: 100
        }

        model: testScheduleModel
    }
}
