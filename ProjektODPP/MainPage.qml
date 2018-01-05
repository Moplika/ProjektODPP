import QtQuick 2.4

MainPageForm {
    tabView.onCurrentIndexChanged: {
        console.log(tabView.currentIndex);

        // Tab: Wszystkie zadania
        if (tabView.currentIndex == 1) {
            if (uiHandler.isInputFileLoaded()) {
                uiHandler.refreshAllTasksTable();
            }
        }

        // Tab: Harmonogram
        if (tabView.currentIndex == 3) {
            if (uiHandler.isOutputFileLoaded()) {
                uiHandler.refreshScheduleTable();
            }
        }
    }


}
