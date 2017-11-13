#include "flowproblemdatareader.h"


#include <iostream>
#include <fstream>

FlowProblem readFlowProblem(std::string filename) {
    std::ifstream inputStream;

    inputStream.open(filename.c_str(), std::ifstream::in);

    if (!inputStream.is_open()) {
        std::cout << "File " << filename << " not opened! " << std::endl;
        return FlowProblem();
    }

    unsigned int taskCount;
    unsigned int stationCount;
    unsigned int machineCount;

    std::vector<double> times;
    std::vector<unsigned int> permutation;

    inputStream >> taskCount >> stationCount >> machineCount;

//    // Debug
//    std::cout << "Task count: " << taskCount << std::endl;
//    std::cout << "Station count: " << stationCount << std::endl;
//    std::cout << "Machine count: " << machineCount << std::endl;

    times.push_back(0.0); //Czas dla zerowego zadania
    for (unsigned int i = 1; i < taskCount*stationCount+1; i++) {
        double time;
        inputStream >> time;
        times.push_back(time);
    }

//    // Debug
//    std::cout << "Times: " << std::endl;
//    for (std::vector<double>::iterator it = times.begin();
//         it != times.end(); it++) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;

    for (unsigned int i = 0; i < taskCount*stationCount + stationCount * machineCount + 1; i++) {
        unsigned int taskNumber;
        inputStream >> taskNumber;
        permutation.push_back(taskNumber);
    }

//    // Debug
//    std::cout << "Permutation: ";
//    for (std::vector<unsigned int>::iterator it = permutation.begin();
//         it != permutation.end(); it++) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;

    inputStream.close();

    FlowProblem flowProblem(taskCount, stationCount, machineCount);
    flowProblem.setData(times, permutation);


    return flowProblem;
}

void readSolution(std::string filename, double &expectedCmax,
                  std::vector<double> &expectedTimes) {
    std::ifstream inputStream;

    inputStream.open(filename.c_str(), std::ifstream::in);

    if (!inputStream.is_open()) {
        std::cout <<"File "<< filename <<  " not opened!";
        return;
    }

    inputStream >> expectedCmax;

//    // Debug
//    std::cout << expectedCmax << std::endl;

    expectedTimes.clear();

    while(inputStream.good()) {
        double value;
        inputStream >> value;

        if (inputStream.eof()) {
            break;
        }

        expectedTimes.push_back(value);
    }

//    // Debug
//    for (auto time : expectedTimes) {
//        std::cout << time << " ";
//    }
//    std::cout << std::endl;







    inputStream.close();
}
