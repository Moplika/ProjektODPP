import QtQuick 2.4
import QtQml 2.2

ButtonBarForm {
    property string dateString

    btn_saveSchedule.enabled: false;
    label_lastSchedule.text: "Harmonogram nie został jeszcze wyznaczony"

    btn_findSchedule.onClicked: {
        label_lastSchedule.text = "Trwa wyznaczanie harmonogramu"
        btn_saveSchedule.enabled = false;
        uiHandler.startCalculations();


    }

    Connections {
        target: uiHandler;
        onCalculationFinished: {
            dateString = new Date().toLocaleTimeString(Qt.locale(), "hh:mm");

            label_lastSchedule.text = "Ostatni harmonogram wyznaczono " + dateString;
            btn_saveSchedule.enabled = true;
        }
    }
}
