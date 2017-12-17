#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <QObject>

class UIHandler : public QObject
{
    Q_OBJECT
public:
    explicit UIHandler(QObject *parent = nullptr);

signals:
    void testSignal();

public slots:
    void startCalculations();

    bool addNewClient(int clientNumber, QString clientName, double stage1Time,
                      double stage2Time, double stage3Time, double stage4Time);

private:
    void calculateSchedule();

    bool isNan(double number);

};

#endif // UIHANDLER_H
