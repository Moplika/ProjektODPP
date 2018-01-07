import QtQuick 2.0

Item {
    property int lineWidth: 1
    property int lineSpacing: 5

    Column {
        width: parent.width
        height: parent.height

        Rectangle {
            height: lineSpacing
            width: parent.width
            color: "#00000000"
        }

        Rectangle {
            height: lineWidth
            width: parent.width
            color: "darkGrey"
        }

        Rectangle {
            height: lineSpacing
            width: parent.width
            color: "#00000000"
        }
    }


}
