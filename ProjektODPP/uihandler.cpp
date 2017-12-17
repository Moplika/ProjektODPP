#include "uihandler.h"

#include <QtConcurrent/qtconcurrentrun.h>
#include "cmaxtesting.h"


UIHandler::UIHandler(QObject *parent) : QObject(parent)
{

}

void UIHandler::startCalculations() {
    //this->calculateSchedule();
    QFuture<void> t1 = QtConcurrent::run(this, calculateSchedule);
//    t1.waitForFinished();

}

void UIHandler::calculateSchedule() {
    //TODO: Wczytanie danych i wykonanie faktycznych obliczeń
    tabuListTest(10000, 20, "C:\\Users\\Monia\\Desktop\\FlexFlowShop\\ex20_5.txt");
    emit testSignal();
}
