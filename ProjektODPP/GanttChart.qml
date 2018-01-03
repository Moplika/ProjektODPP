import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls 2.2 as C
import QtQuick.Layouts 1.3

Item {
    id: window

    property int viewWidth: 10000
    property int rowHeight: 20

    anchors.fill: parent

    C.ScrollView {
        id: scrollView
        anchors.fill: parent
        clip: true

        ColumnLayout {
            id: columnLayout
            y: 50
            width: viewWidth
            height: parent.height
            spacing: 0

            GanttChartRow {
                id: row1
                width: viewWidth
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row2
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row3
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row4
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row5
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row6
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row7
                height: rowHeight + 5
                rowHeight: rowHeight
            }
            GanttChartRow {
                id: row8
                height: rowHeight + 5
                rowHeight: rowHeight
            }
        }
    }

    Connections {
        target: uiHandler
        onStartGanttDrawing: {
            var unit = Math.max(window.width / cMax, 8);
            console.log("Unit: ", unit);

            viewWidth = cMax*unit;
            console.log("Width: ", viewWidth);
            console.log("Real width:", scrollView.width)

            row1.unit = unit;
            row2.unit = unit;
            row3.unit = unit;
            row4.unit = unit;
            row5.unit = unit;
            row6.unit = unit;
            row7.unit = unit;
            row8.unit = unit;
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

    }


}
