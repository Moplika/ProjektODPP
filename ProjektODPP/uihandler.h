#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <QObject>
#include <QUrl>
#include <string>
#include "flowproblem.h"
#include "datareader.h"

class UIHandler : public QObject
{
    Q_OBJECT
public:
    explicit UIHandler(QObject *parent = nullptr);

signals:
    void calculationFinished(double cMax);

    void addAllTasksRow(QList<QString> rowValues);
    void clearAllTasksTable();
    void addScheduleRow(QList<QString> rowValues);
    void clearScheduleTable();

    void startGanttDrawing(double cMax, double minLength, double maxLength);

    void drawGanttRow(int rowId, int elementCount, QList<QString> elementIndexes,
                      QList<double>gaps, QList<double>lengths);

    void inputFileOpened();
    void inputFileNotOpened();
    void newFileCreated();

    void outputSaved();
    void outputNotSaved();

    void updateCMax(double cMax);

public slots:
    void startCalculations();

    bool addNewClient(int clientNumber, QString clientName, double stage1Time,
                      double stage2Time, double stage3Time, double stage4Time);

    void refreshAllTasksTable();
    void refreshScheduleTable();

    void refreshGanttChart();

    void createNewInputFile(QUrl filePath);
    void openInputFile(QUrl filePath);
    void saveToFile(QUrl filePath);

    bool isInputFileLoaded();
    bool isOutputFileLoaded();
    bool wasScheduleCalculated();

private:
    void calculateSchedule();

    void createAllTasksRow();
    void createScheduleRow();

    bool isNan(double number);

    FlowProblem flowProblem;
    DataReader dataReader;
    std::string filepathIn;
    std::string filepathOut;

    bool isInputLoaded;
    bool isOutputLoaded;
    bool wasCalculated;


};

#endif // UIHANDLER_H
