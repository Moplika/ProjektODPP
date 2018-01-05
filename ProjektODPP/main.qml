import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "New"
                shortcut: StandardKey.New
            }

            MenuItem {
                text: "Open"
                shortcut: StandardKey.Open
                onTriggered: fileDialog.open()
//                onTriggered: uiHandler.openInputFile()
            }
            MenuItem {
                text: "Save"
                shortcut: StandardKey.Save
            }
            MenuSeparator {}
            MenuItem {
                text: "Close"
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
        id: fileDialog
        title: "Wybierz plik wejsciowy: "
        onAccepted: {
            uiHandler.openInputFile(fileUrl);
        }
    }
}
