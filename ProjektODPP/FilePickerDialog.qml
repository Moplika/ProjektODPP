import QtQuick 2.2
import QtQuick.Dialogs 1.0

FileDialog {
    id: fileDialog
    title: "Wybierz plik"
    folder: shortcuts.desktop
    selectMultiple: false
    selectFolder: false
    nameFilters: [ "Pliki csv (*.csv)", "Wszystkie pliki (*)" ]
    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrl)
    }
    onRejected: {
        console.log("Canceled")
    }
}
