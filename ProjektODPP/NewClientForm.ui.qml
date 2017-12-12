import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 800
    height: 400
    property alias btn_addClient: btn_addClient
    property alias text_timeStage4: text_timeStage4
    property alias text_timeStage3: text_timeStage3
    property alias text_timeStage2: text_timeStage2
    property alias text_timeStage1: text_timeStage1
    property alias text_clientName: text_clientName
    property alias text_clientId: text_clientId
    property alias text_orderId: text_orderId

    Rectangle {
        id: rectangle
        border.color: "#00000000"
        anchors.fill: parent
    }

    GridLayout {
        id: gridLayout
        height: 400
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.fill: parent
        rows: 9
        columns: 5

        Label {
            id: label_orderID
            text: qsTr("Nr zamówienia")
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextField {
            id: text_orderId
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.maximumWidth: 65535
            Layout.preferredWidth: 450
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.preferredHeight: 35
            Layout.fillHeight: true
        }

        Rectangle {
            id: blank_row1
            width: 200
            height: 200
            color: "#00000000"
            Layout.preferredWidth: 150
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.columnSpan: 1
            border.color: "#00000000"
            Layout.preferredHeight: 35
            Layout.fillWidth: true
        }

        Label {
            id: label_clientId
            text: qsTr("Nr klienta")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_clientId
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: -1
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }

        Rectangle {
            id: blank_row2
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Label {
            id: label_clientName
            text: qsTr("Nazwa klienta")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_clientName
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: -1
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }

        Rectangle {
            id: blank_row3
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Rectangle {
            id: blank_row4
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.columnSpan: 5
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Label {
            id: label_timeStage1
            text: qsTr("Czas etapu 1")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_timeStage1
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: false
            Layout.columnSpan: 2
        }

        Rectangle {
            id: blank_row5
            width: 200
            height: 200
            color: "#00000000"
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            Layout.columnSpan: 2
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Label {
            id: label_timeStage5
            text: qsTr("Czas etapu 2")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_timeStage2
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: false
            Layout.columnSpan: 2
        }

        Rectangle {
            id: blank_row6
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.columnSpan: 2
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Label {
            id: label_timeStage6
            text: qsTr("Czas etapu 3")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_timeStage3
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: false
            Layout.columnSpan: 2
        }

        Rectangle {
            id: blank_row7
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.columnSpan: 2
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Label {
            id: label_timeStage7
            text: qsTr("Czas etapu 4")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 150
        }

        TextField {
            id: text_timeStage4
            text: qsTr("")
            Layout.maximumHeight: 50
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: false
            Layout.columnSpan: 2
        }

        Rectangle {
            id: blank_row8
            width: 200
            height: 200
            color: "#00000000"
            Layout.fillHeight: true
            Layout.columnSpan: 2
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Rectangle {
            id: blank_row9
            width: 200
            height: 200
            color: "#00000000"
            Layout.columnSpan: 4
            Layout.fillHeight: true
            Layout.preferredHeight: 35
            Layout.fillWidth: true
            border.color: "#00000000"
        }

        Button {
            id: btn_addClient
            text: qsTr("Dodaj zamówienie")
            font.pointSize: 10
            Layout.preferredWidth: 150
            Layout.fillWidth: true
        }





    }
}
