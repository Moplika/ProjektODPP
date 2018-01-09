import QtQuick 2.4

ScheduleForm {

    btn_refresh.enabled: false;

    label_cmax.text: " "

    btn_refresh.onClicked: uiHandler.refreshScheduleTable();

    Connections {
        target: uiHandler;
        onAddScheduleRow: {
            addRow(rowValues);
        }
        onClearScheduleTable: {
//            label_cmax.text = " "
            scheduleModel.clear();
        }

        onInputFileOpened: {
            btn_refresh.enabled = false;
            scheduleModel.clear();
            label_cmax.text = " "

        }

        onCalculationFinished: {
            btn_refresh.enabled = true;
            uiHandler.refreshScheduleTable();
            label_cmax.text = cMax.toString();
        }

    }

    function addRow(rowValues) {
        var params = {
            recordId: rowValues[0],
            clientId: rowValues[1],
            clientName: rowValues[2],
            stageId: rowValues[3],
            teamId: rowValues[4],
            executionTime: rowValues[5],
            startTime: rowValues[6],
            endTime: rowValues[7]
        }

        scheduleModel.append(params);
    }
}
