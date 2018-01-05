import QtQuick 2.4

MainPageForm {
    tabView.onCurrentIndexChanged: {
        console.log(tabView.currentIndex);

        // Tab: Wszystkie zadania
        if (tabView.currentIndex == 2) {
            if (uiHandler.isInputFileLoaded()) {
                uiHandler.refreshAllTasksTable();
            }
        }

        // Tab: Wykres Gantta
        if (tabView.currentIndex == 3) {
            if (uiHandler.wasScheduleCalculated()) {
                uiHandler.refreshGanttChart();
            }
        }

        // Tab: Harmonogram
        if (tabView.currentIndex == 4) {
            if (uiHandler.isOutputFileLoaded()) {
                uiHandler.refreshScheduleTable();
            }
        }
    }


}
