import QtQuick 2.4
import QtQml 2.2

ButtonBarForm {
    property string dateString

    btn_saveSchedule.enabled: false;
    btn_findSchedule.enabled: false;
    label_lastSchedule.text: "Brak pliku wejściowego. Otwórz plik lub utwórz nowy"

    btn_findSchedule.onClicked: {
        label_lastSchedule.text = "Trwa wyznaczanie harmonogramu"
        btn_saveSchedule.enabled = false;
        uiHandler.startCalculations();
    }

    btn_saveSchedule.onClicked: {
        fileDialog.open();
    }

    Connections {
        target: uiHandler;
        onInputFileOpened: {
            label_lastSchedule.text = "Harmonogram nie został jeszcze wyznaczony"
            label_lastSchedule.color = "black"
            btn_findSchedule.enabled = true;
        }
        onInputFileNotOpened: {
            label_lastSchedule.text = "Błąd otwarcia pliku wejściowego"
            label_lastSchedule.color = "red"
        }

        onCalculationFinished: {
            dateString = new Date().toLocaleTimeString(Qt.locale(), "hh:mm");

            label_lastSchedule.text = "Ostatni harmonogram wyznaczono " + dateString;
            btn_saveSchedule.enabled = true;
        }

    }

    FilePickerDialog {
        id: fileDialog
        title: "Wybierz plik wyjsciowy: "
        selectExisting: false
        onAccepted: {
            uiHandler.saveToFile(fileUrl);
        }
    }
}
