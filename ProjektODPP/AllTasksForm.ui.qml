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
