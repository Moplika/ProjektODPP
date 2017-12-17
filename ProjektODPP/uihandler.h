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

private:
    void calculateSchedule();

};

#endif // UIHANDLER_H
