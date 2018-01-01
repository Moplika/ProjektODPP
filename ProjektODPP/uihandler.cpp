#include "uihandler.h"

#include <iostream>
#include <QString>
#include <QtConcurrent/qtconcurrentrun.h>
#include "cmaxtesting.h"
#include "flowproblemdatareader.h"


UIHandler::UIHandler(QObject *parent) : QObject(parent)
{

}

void UIHandler::startCalculations() {
    QFuture<void> t1 = QtConcurrent::run(this, calculateSchedule);
    //    t1.waitForFinished();

}

void UIHandler::calculateSchedule() {
    //TODO: Wczytanie danych i wykonanie faktycznych obliczeń
    flowProblem = readFlowProblem("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\ex20_5.txt");

    double firstCmax = flowProblem.getCMax();

    std::cout << "Początkowe cMax: " << firstCmax << std::endl;

    flowProblem.printCriticalPath();

    std::vector<unsigned int> bestPermutation;
    double bestCMax = flowProblem.doTabuSearch(10000, 20, bestPermutation);
    flowProblem.setPermutation(bestPermutation);

    flowProblem.printCurrentPermutation();
    std::cout << "Najlepsze otrzymane cMax: " << bestCMax << std::endl;

    this->refreshGanttChart();

//    tabuListTest(10000, 20, "C:\\Users\\Monia\\Desktop\\FlexFlowShop\\ex20_5.txt");



    emit testSignal();
}

bool UIHandler::addNewClient(int clientNumber, QString clientName, double stage1Time,
                             double stage2Time, double stage3Time, double stage4Time) {

    if (clientNumber == 0 || isNan(stage1Time) || stage1Time == 0 || isNan(stage2Time)
            || stage2Time == 0 || isNan(stage3Time) || stage3Time == 0 ||
            isNan(stage4Time) || stage4Time == 0 ) {
        std::cout << "Bledne parametry :(" << std::endl;
        return false;
    }

    std::cout << "Nowe zamówienie: " << std::endl;
    std::cout << clientNumber << "   " << clientName.toStdString() << std::endl;
    std::cout << stage1Time << "   " << stage2Time << "   " << stage3Time << "   " << stage4Time << std::endl;

    return true;
}

void UIHandler::refreshAllTasksTable() {
    // TODO: Odświeżanie całej tabeli
    // TEMP: Tylko dodawanie nowego rzędu
    this->createAllTasksRow();
}

void UIHandler::refreshScheduleTable() {
    // TODO: Odświeżanie całej tabeli
    // TEMP: Tylko dodawanie nowego rzędu
    this->createScheduleRow();
}

void UIHandler::refreshGanttChart() {
    auto permutation = flowProblem.getCurrentPermutation();
    auto taskTimes = flowProblem.getTaskTimes();
    auto startTimes = flowProblem.getStartTimes();
    auto finishTimes = flowProblem.getFinishTimes();

    QList<QString> indexes;
    QList<double> gaps;
    QList<double> lengths;

    double endOfPrevious = 0;
    int elementCount = 0;

    for (auto it = permutation.begin() + 1; it != permutation.end(); it++) {
        int index = *it;

        if (index == 0) {
            // Skonczona jedna maszyna
            emit drawGanttRow(elementCount, indexes, gaps, lengths);

            // Wyzerowanie dla następnego rzędu
            elementCount = 0;
            indexes.clear();
            gaps.clear();
            lengths.clear();

            break; //TEMP
        } else {
            // Dalej na maszynie, dodaj elementy do wektorow
            double taskTime = taskTimes.at(index);
            double startTime = startTimes.at(index);
            double gap = startTime - endOfPrevious;
            endOfPrevious = finishTimes.at(index);

            elementCount++;
            indexes.push_back(QString::number(index));
            lengths.push_back(taskTime);
            gaps.push_back(gap);
        }




    }

}

void UIHandler::createAllTasksRow() {
    // TODO: Dodać czytanie faktycznych wartości z pliku

    QList<QString> rowValues;

    rowValues.push_back("7");
    rowValues.push_back("123456");
    rowValues.push_back("Test klient");
    rowValues.push_back("48");
    rowValues.push_back("12");
    rowValues.push_back("42");
    rowValues.push_back("87");


    emit addAllTasksRow(rowValues);
}

void UIHandler::createScheduleRow() {
    // TODO: Dodać czytanie faktycznych wartości z pliku
    QList<QString> rowValues;

    rowValues.push_back("7");
    rowValues.push_back("123456");
    rowValues.push_back("Test klient");
    rowValues.push_back("2");
    rowValues.push_back("4");
    rowValues.push_back("24");
    rowValues.push_back("87");
    rowValues.push_back("111");

    emit addScheduleRow(rowValues);

}

bool UIHandler::isNan(double number) {
    // Jeśli jest NaNem, to zwróci true
    return number != number;
}
