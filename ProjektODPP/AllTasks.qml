import QtQuick 2.4

AllTasksForm {

    function addRow(rowValues) {
        var params = {
            recordId: rowValues[0],
            clientId: rowValues[1],
            clientName: rowValues[2],
            stage1Time: rowValues[3],
            stage2Time: rowValues[4],
            stage3Time: rowValues[5],
            stage4Time: rowValues[6]
        }

        allTasksModel.append(params);
    }

    btn_refresh.onClicked: uiHandler.refreshAllTasksTable();

    Connections {
        target: uiHandler;
        onAddAllTasksRow: {
            addRow(rowValues);
        }

    }
}

