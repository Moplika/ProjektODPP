import QtQuick 2.4
import QtQuick.Controls 1.4 as C
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: window
    width: 800
    height: 560
    property alias tableView: tableView
    property alias btn_refresh: btn_refresh
    property alias allTasksModel: allTasksModel

    property int widthUnit: window.width/15

    Rectangle {
        id: background
        width: 200
        height: 200
        color: "#ffffff"
        anchors.fill: parent
    }

    ListModel {
        id: allTasksModel
//        ListElement {
//            recordId: "1"
//            clientId: "121587"
//            clientName: "Kowalski & Spolka"
//            stage1Time: "25"
//            stage2Time: "147"
//            stage3Time: "85"
//            stage4Time: "12"
//        }
//        ListElement {
//            recordId: "2"
//            clientId: "134597"
//            clientName: "Abracadabra"
//            stage1Time: "67"
//            stage2Time: "32"
//            stage3Time: "54"
//            stage4Time: "54"
//        }
//        ListElement {
//            recordId: "3"
//            clientId: "145673"
//            clientName: "Alkohole Świata"
//            stage1Time: "145"
//            stage2Time: "75"
//            stage3Time: "24"
//            stage4Time: "74"
//        }
//        ListElement {
//            recordId: "4"
//            clientId: "123789"
//            clientName: "Pojemniki i swieczki"
//            stage1Time: "23"
//            stage2Time: "785"
//            stage3Time: "45"
//            stage4Time: "120"
//        }
//        ListElement {
//            recordId: "5"
//            clientId: "215493"
//            clientName: "Domy Nowaka"
//            stage1Time: "20"
//            stage2Time: "58"
//            stage3Time: "13"
//            stage4Time: "24"
//        }
//        ListElement {
//            recordId: "6"
//            clientId: "215493"
//            clientName: "Domy Nowaka"
//            stage1Time: "87"
//            stage2Time: "123"
//            stage3Time: "64"
//            stage4Time: "54"
//        }
    }

    C.TableView {
        id: tableView
        x: 0
        y: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top: btn_refresh.bottom
        anchors.topMargin: 5
        Layout.fillHeight: true
        Layout.fillWidth: true
        C.TableViewColumn {
            role: "recordId"
            title: "Lp"
            width: widthUnit
        }
        C.TableViewColumn {
            role: "clientId"
            title: "Numer klienta"
            width: 2*widthUnit
        }
        C.TableViewColumn {
            role: "clientName"
            title: "Nazwa klienta"
            width: 4*widthUnit
        }
        C.TableViewColumn {
            role: "stage1Time"
            title: "Czas etapu 1"
            width: 2*widthUnit
        }
        C.TableViewColumn {
            role: "stage2Time"
            title: "Czas etapu 2"
            width: 2*widthUnit
        }
        C.TableViewColumn {
            role: "stage3Time"
            title: "Czas etapu 3"
            width: 2*widthUnit
        }
        C.TableViewColumn {
            role: "stage4Time"
            title: "Czas etapu 4"
            width: 2*widthUnit
        }

        model: allTasksModel
    }


    Button {
        id: btn_refresh
        x: 690
        y: 10
        height: 30
        text: qsTr("Odśwież")
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
    }



}
