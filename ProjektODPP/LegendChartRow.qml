import QtQuick 2.0
import QtQuick.Controls 1.0


Item {
    id: item1
    property var indexes: []
    property int lineWidth: 1
    property int lineGap: 50
    property int numberWidth: 30
    property int unit: 5
    property int rowHeight: 35
    property int machineId: 1

    Row {
        x: 0
        y: 0
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            id: rowRepeater
            model: 0

            Row{
                id: row


                Rectangle {
                    id: legendBar
                    width: lineWidth
                    height: rowHeight
                    color: "black"
                    border.color: "black"
                    border.width: 1

                }


                Text {
                    id: legendTextSpace
                    width: 5
                    text: "   "
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }

                Text {
                    id: legendText
                    width: numberWidth
                    text: indexes[index]
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                }

                Rectangle {
                    id: legendBreak
                    width: lineGap * unit - numberWidth - 5 - lineWidth
                    height: rowHeight
                    color: "#00000000"
                }
            }
        }
    }


    function drawRow(elementCount, elementIndexes) {
        rowRepeater.model = elementCount;
        indexes = elementIndexes;
    }

    function clear() {
        rowRepeater.model = 0;
    }


}
