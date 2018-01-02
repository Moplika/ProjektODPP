#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <QObject>
#include "flowproblem.h"

class UIHandler : public QObject
{
    Q_OBJECT
public:
    explicit UIHandler(QObject *parent = nullptr);

signals:
    void testSignal();

    void addAllTasksRow(QList<QString> rowValues);
    void addScheduleRow(QList<QString> rowValues);

    void startGanttDrawing(double cMax, double minLength, double maxLength);

    void drawGanttRow(int rowId, int elementCount, QList<QString> elementIndexes,
                      QList<double>gaps, QList<double>lengths);

public slots:
    void startCalculations();

    bool addNewClient(int clientNumber, QString clientName, double stage1Time,
                      double stage2Time, double stage3Time, double stage4Time);

    void refreshAllTasksTable();
    void refreshScheduleTable();

    void refreshGanttChart();

private:
    void calculateSchedule();

    void createAllTasksRow();
    void createScheduleRow();

    bool isNan(double number);

    FlowProblem flowProblem;

};

#endif // UIHANDLER_H
