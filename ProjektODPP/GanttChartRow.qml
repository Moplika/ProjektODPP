import QtQuick 2.0
import QtQuick.Controls 1.0


Item {
    id: item1
    property var colors: [
        "#3A5869",
        "#45B29D",
        "#EFC94C",
        "#E27A3F",
        "#DF5A49",
        "#41BF71",
        "#44BEC9"
    ]
    property var elementWidths: []
    property var gapTimes: []
    property var indexes: []
    property int unit: 5
    property int rowHeight: 35
    property int machineId: 1

    Row {
        x: 0
        y: 0
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            id: rowRepeater
            model: 10

            Row{
                Rectangle {
                    width: gapTimes[index]*unit
                    height: rowHeight
                    color: "#00000000"
                }
                Rectangle {
                    width: elementWidths[index]*unit
                    height: rowHeight
                    color: colors[(machineId + index) % colors.length]
                    border.color: "black"
                    border.width: 1
                    Text {
                        anchors.fill: parent
                        text: indexes[index]
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }
    }


    function drawRow(rowId, elementCount, elementIndexes, gaps, lengths) {
        machineId = rowId;
        rowRepeater.model = elementCount;
        indexes = elementIndexes;
        gapTimes = gaps;
        elementWidths = lengths;
    }

    function clear() {
        rowRepeater.model = 0;
    }

}
