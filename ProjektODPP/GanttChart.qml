import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls 2.2 as C

Item {
    id: item1
    property var colors: ["red", "green", "blue"]
    property var elementWidths: [1, 2, 3, 4, 5, 6, 7, 8, 9]
    property var gapTimes: [9,8,7,6,5,4,3,2,1]
    property var indexes: ["31","6","1","96","76","26","56","71","59"]
    property int unit: 2

    anchors.fill: parent

    C.ScrollView {
        anchors.fill: parent
        clip: true

//        C.ScrollBar.horizontal: C.ScrollBar.AlwaysOn

//        Row {
//            Repeater {
//                model: 10

//                Row{
//                    Rectangle {
//                        width: 1
//                        height: 1
//                        color: "black"
//                        Text {
//                            anchors.fill: parent
//                            text: 100*index
//                            verticalAlignment: Text.AlignVCenter
//                            horizontalAlignment: Text.AlignHCenter
//                        }
//                    }
//                    Rectangle {
//                        width: 100
//                        height: 1
//                        color: "#00000000"
//                    }
//                }
//            }
//        }

        Row {
            x: 0
            y: 274

            Repeater {
                id: rowRepeater
                model: 10

                Row{
                    Rectangle {
                        width: gapTimes[index]*unit
                        height: 35
                        color: "#00000000"
                    }
                    Rectangle {
                        width: elementWidths[index]*unit
                        height: 35
                        color: colors[index%3]
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

//        Button {
//            id: button
//            width: 300
//            height: 100
//            text: qsTr("Button")
//            anchors.left: parent.left
//            anchors.leftMargin: 0
//            anchors.bottom: parent.bottom
//            anchors.bottomMargin: 0

//            onClicked: {
//                uiHandler.refreshGanttChart();
//    //            drawRow(5,["1","2","3","4","5"],[5,7,6,1,4],[12,2,7,5,6])
//            }
//        }
    }

    Connections {
        target: uiHandler
        onDrawGanttRow:
            drawRow(elementCount, elementIndexes, gaps, lengths)
    }

    function drawRow(elementCount, elementIndexes, gaps, lengths) {
        rowRepeater.model = elementCount;
        indexes = elementIndexes;
        gapTimes = gaps;
        elementWidths = lengths;


    }

}
