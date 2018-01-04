import QtQuick 2.2
import QtQuick.Dialogs 1.0

FileDialog {
    id: fileDialog
    title: "Wybierz plik wejsciowy"
    folder: shortcuts.desktop
    nameFilters: [ "Pliki csv (*.csv)", "Wszystkie pliki (*)" ]
    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrl)
        uiHandler.openInputFile(fileUrl);
    }
    onRejected: {
        console.log("Canceled")
    }
}
