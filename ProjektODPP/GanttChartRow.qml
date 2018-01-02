import QtQuick 2.0
import QtQuick.Controls 1.0


Item {
    property var colors: [
        "#3A5869",
        "#45B29D",
        "#EFC94C",
        "#E27A3F",
        "#DF5A49",
        "#41BF71",
        "#44BEC9"
    ]
    property var elementWidths: [1, 2, 3, 4, 5, 6, 7, 8, 9]
    property var gapTimes: [9,8,7,6,5,4,3,2,1]
    property var indexes: ["31","6","1","96","76","26","56","71","59"]
    property int unit: 5
    property int rowHeight: 35
    property int machineId: 1

    Row {
        x: 0
        y: 0

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
//                    color: colors[Math.floor(Math.random() * colors.length)]
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

}
