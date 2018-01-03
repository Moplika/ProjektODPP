#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <iostream>
#include <algorithm>

#include "flowproblem.h"
#include "cmaxtesting.h"
#include "flowproblemdatareader.h"
#include "uihandler.h"
#include "datareader.h"

void testDataReading();

int main(int argc, char *argv[])
{
    //Kod pokazujący interfejs, nie usuwać
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    UIHandler uiHandler;
    engine.rootContext()->setContextProperty(QString("uiHandler"), &uiHandler);

    testDataReading();

    return app.exec();


//        mojPrzykladTest();
    //    std::cout << "Sama sciezka krytyczna: " << std::endl;
    //    criticalPathTest();
    //    std::cout << "Wynik testu 20_5: " << test20_5() << std::endl;
    //    std::cout << "Wynik testu 20_10: " << test20_10() << std::endl;
    //    std::cout << "Wynik testu 20_20: " << test20_20() << std::endl;
    //    std::cout << "Wynik testu 50_5: " << test50_5() << std::endl;
    //    std::cout << "Wynik testu 50_10: " << test50_10() << std::endl;
    //    std::cout << "Wynik testu 50_20: " << test50_20() << std::endl;
    //    std::cout << "Wynik testu 100_5: " << test100_5() << std::endl;
    //    std::cout << "Wynik testu 100_10: " << test100_10() << std::endl;

    //    FlowProblem test = readFlowProblem("C:\\Users\\Monika\\Desktop\\FlexFlowShop\\ex20_5.txt");
    //    std::vector<double> times = test.getTotalTimes();

    //    double expectedCMax = 0;
    //    std::vector<double> expectedTimes;

    //    readSolution("C:\\Users\\Monika\\Desktop\\FlexFlowShop\\ex20_5.out", expectedCMax, expectedTimes);

    //    FlowProblem flowProblem(4,2,2);
    //    flowProblem.printPreviousTasks();

//    permutationSwapingTest();
//        permutationSwapingTest15_22();
//    permutationSwapAllFiles();

//        tabuListTest();
//    tabuListTest(10000, 20, "C:\\Users\\Monia\\Desktop\\FlexFlowShop\\ex20_5.txt");
//          stationBoundriesTest();



    return 0;
}

void testDataReading() {
    std::cout << "Czy cos w ogole dziala" << std::endl;
    std::vector <int> Poczatki = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    std::vector <int> Konce = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    std::vector <unsigned int> Permutacje = { 0,1,9,13,0,5,21,17,0,14,6,10,0,2,22,18,0,7,23,3,0,11,15,19,0,12,8,20,16,0,4,24,0 };
    DataReader Dane;
    std::cout << "Udalo sie utworzyc obiekt" << std::endl;
    Dane.Odczyt_Pliku("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\formaty1.csv");
    std::cout << "Odczytano plik" << std::endl;
    Dane.Dodaj_Rekord("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\formaty1.csv",121312,"Bolek i Lolek",12,113,15,16);
    std::cout << "Dodal jakis rekord" << std::endl;
    Dane.Stworz_Wektor_In("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\formaty1.csv");
    std::cout << "Strorzono wektor" << std::endl;
    Dane.Stworz_Wektor_Out("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\wyniki.csv");
    std::cout << "Strorzono wektor" <<std:: endl;
    Dane.Wyniki("C:\\Users\\Monia\\Desktop\\FlexFlowShop\\wyniki.csv", Poczatki, Konce, Permutacje);
    std::cout << "No i koniec" << std::endl;
}



