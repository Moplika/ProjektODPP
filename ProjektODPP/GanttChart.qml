import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls 2.2 as C
import QtQuick.Layouts 1.3

Item {
    id: window

    property int viewWidth: 10000
    property int rowHeight: 20
    property int lineWidth: 1
    property int lineSpacing: 10
    property int rowSpacing: 3
    property int maxLegendEntry: 100
    property int legendSpacing: 50

    anchors.fill: parent

    C.ScrollView {
        id: scrollView
        anchors.fill: parent
        clip: true

        RowLayout {
            id: rowLayout
            y: 15
            spacing: 5

            ColumnLayout {
                y: 0
                width: 50
                height: parent.height
                Layout.preferredHeight: 371
                Layout.preferredWidth: 50
                Layout.fillHeight: true
                Layout.fillWidth: false
                spacing: 8

                Text {
                    height: rowHeight + 5
                    text: ""
                    Layout.preferredHeight: 35
                }

                Text {
                    height: 2*rowHeight
                    text: "Etap 1: "
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredHeight: 75
                    Layout.rowSpan: 2
                    Layout.columnSpan: 1
                }

                Text {
                    height: 2*rowHeight
                    text: "Etap 2: "
                    Layout.fillWidth: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    Layout.preferredHeight: 75
                    Layout.columnSpan: 2
                }

                Text {
                    height: 2*rowHeight
                    text: "Etap 3: "
                    Layout.fillWidth: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    Layout.preferredHeight: 75
                    Layout.rowSpan: 2
                }
                Text {
                    height: 2*rowHeight
                    text: "Etap 4: "
                    Layout.fillWidth: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    Layout.preferredHeight: 75
                    Layout.rowSpan: 2
                }

            }

            Rectangle {
                height: parent.height
                width: 1
                color: "darkgrey"
                Layout.maximumWidth: 1
                Layout.minimumWidth: 1
                Layout.preferredWidth: 1
                Layout.fillWidth: false
                Layout.fillHeight: true
            }

            ColumnLayout {
                id: columnLayout
                width: viewWidth
                height: parent.height
                spacing: 0

                LegendChartRow {
                    id: legendRow
                    width: viewWidth
                    height: rowHeight
                    Layout.fillHeight: false
                    rowHeight: rowHeight
                }


                Line {
                    width: parent.width
                    height: lineWidth + 2*lineSpacing
                    lineWidth: lineWidth
                    lineSpacing: lineSpacing
                }

                GanttChartRow {
                    id: row1
                    width: viewWidth
                    height: rowHeight
                    Layout.fillHeight: false
                    rowHeight: rowHeight
                }
                Rectangle {
                    height: rowSpacing
                    width: parent.width
                    color: "#00000000"
                }
                GanttChartRow {
                    id: row2
                    height: rowHeight
                    rowHeight: rowHeight
                }

                Line {
                    width: parent.width
                    height: lineWidth + 2*lineSpacing
                    lineWidth: lineWidth
                    lineSpacing: lineSpacing
                }

                GanttChartRow {
                    id: row3
                    height: rowHeight
                    rowHeight: rowHeight
                }
                Rectangle {
                    height: rowSpacing
                    width: parent.width
                    color: "#00000000"
                }
                GanttChartRow {
                    id: row4
                    height: rowHeight
                    rowHeight: rowHeight
                }

                Line {
                    width: parent.width
                    height: lineWidth + 2*lineSpacing
                    lineWidth: lineWidth
                    lineSpacing: lineSpacing
                }

                GanttChartRow {
                    id: row5
                    height: rowHeight
                    rowHeight: rowHeight
                }
                Rectangle {
                    height: rowSpacing
                    width: parent.width
                    color: "#00000000"
                }
                GanttChartRow {
                    id: row6
                    height: rowHeight
                    rowHeight: rowHeight
                }

                Line {
                    width: parent.width
                    height: lineWidth + 2*lineSpacing
                    lineWidth: lineWidth
                    lineSpacing: lineSpacing
                }

                GanttChartRow {
                    id: row7
                    height: rowHeight
                    rowHeight: rowHeight
                }
                Rectangle {
                    height: rowSpacing
                    width: parent.width
                    color: "#00000000"
                }
                GanttChartRow {
                    id: row8
                    height: rowHeight
                    rowHeight: rowHeight
                }
            }
        }
    }

    Connections {
        target: uiHandler
        onStartGanttDrawing: {
            var unit = Math.max(window.width / cMax, 8);

            viewWidth = cMax*unit;
            columnLayout.width = viewWidth;
            rowLayout.width = viewWidth;

            row1.unit = unit;
            row2.unit = unit;
            row3.unit = unit;
            row4.unit = unit;
            row5.unit = unit;
            row6.unit = unit;
            row7.unit = unit;
            row8.unit = unit;

            getLegendProperties(cMax, unit);
        }

        onDrawGanttRow: {
            switch(rowId) {
            case 1:
                row1.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 2:
                row2.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 3:
                row3.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 4:
                row4.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 5:
                row5.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 6:
                row6.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 7:
                row7.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;
            case 8:
                row8.drawRow(rowId,elementCount, elementIndexes, gaps, lengths)
                break;

            }
        }

        onInputFileOpened: {
            row1.clear();
            row2.clear();
            row3.clear();
            row4.clear();
            row5.clear();
            row6.clear();
            row7.clear();
            row8.clear();
            legendRow.clear();
        }
    }

    function getLegendProperties(cMax, unit) {
        var elementCount = Math.ceil(cMax / legendSpacing);
        var elementIndexes = ["0"];

        for (var i = 1; i <= elementCount; i++) {
            var indexNb = i*legendSpacing;
            elementIndexes.push(indexNb.toString());
        }

        legendRow.unit = unit;
        legendRow.lineWidth = 1;
        legendRow.lineGap = legendSpacing;
        legendRow.drawRow(elementCount+1, elementIndexes);

//        console.log(elementIndexes);
    }
}


