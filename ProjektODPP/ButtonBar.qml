import QtQuick 2.4

ButtonBarForm {

    btn_findSchedule.onClicked: {
        uiHandler.startCalculations();
    }

    Connections {
        target: uiHandler;
        onTestSignal: {
            label_lastSchedule.text = "Test";
        }
    }
}
