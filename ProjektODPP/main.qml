import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3



ApplicationWindow {
    visible: true
    width: 640
    height: 480
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

    MainPage {
        id: mainForm

        anchors.fill: parent
    }
}
