import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Wyznaczanie harmonogramu")

    menuBar: MenuBar {
        Menu {
            title: "Plik"
            MenuItem {
                text: "Nowy plik wejściowy"
                shortcut: StandardKey.New
                onTriggered: newFileDialog.open()
            }

            MenuItem {
                text: "Otwórz plik wejściowy"
                shortcut: StandardKey.Open
                onTriggered: inputFileDialog.open()
            }
            MenuItem {
                id: menuSave
                text: "Zapisz wyniki obliczeń"
                shortcut: StandardKey.Save
                enabled: false;
                onTriggered: outputFileDialog.open()
            }
            MenuSeparator {}
            MenuItem {
                text: "Zamknij"
                shortcut: StandardKey.Close
                onTriggered: Qt.quit();
            }
        }
    }

    Action {
        id: copyAction
        text: "Copy"
        shortcut: StandardKey.Copy
        iconName: "edit-copy"
        onTriggered: activeFocusItem.copy()
    }

    MainPage {
        id: mainForm

        anchors.fill: parent
    }

    FilePickerDialog {
        id: newFileDialog
        title: "Wybierz plik wejsciowy: "
        selectExisting: false
        onAccepted: {
            uiHandler.createNewInputFile(fileUrl);
        }
    }

    FilePickerDialog {
        id: inputFileDialog
        title: "Wybierz plik wejsciowy: "
        onAccepted: {
            uiHandler.openInputFile(fileUrl);
        }
    }

    FilePickerDialog {
        id: outputFileDialog
        title: "Wybierz plik wyjsciowy: "
        selectExisting: false
        onAccepted: {
            uiHandler.saveToFile(fileUrl);
        }
    }

    Connections {
        target: uiHandler
        onInputFileOpened: {
            menuSave.enabled = false;
        }

        onCalculationFinished: {
            menuSave.enabled = true;
        }

    }

}
