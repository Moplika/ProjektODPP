#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <algorithm>

#include "flowproblem.h"
#include "cmaxtesting.h"
#include "flowproblemdatareader.h"

int main(int argc, char *argv[])
{
/* Kod pokazujący interfejs, nie usuwać
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
*/

    std::cout << "Wynik testu 20_5: " << test20_5() << std::endl;
    std::cout << "Wynik testu 20_10: " << test20_10() << std::endl;
    std::cout << "Wynik testu 20_20: " << test20_20() << std::endl;
    std::cout << "Wynik testu 50_5: " << test50_5() << std::endl;
    std::cout << "Wynik testu 50_10: " << test50_10() << std::endl;
    std::cout << "Wynik testu 50_20: " << test50_20() << std::endl;
    std::cout << "Wynik testu 100_5: " << test100_5() << std::endl;
    std::cout << "Wynik testu 100_10: " << test100_10() << std::endl;

//    FlowProblem test = readFlowProblem("C:\\Users\\Monika\\Desktop\\FlexFlowShop\\ex20_5.txt");
//    std::vector<double> times = test.getTotalTimes();

//    FlowProblem flowProblem(4,2,2);
//    flowProblem.printPreviousTasks();


    return 0;
}




