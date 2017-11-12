#include "flowproblem.h"

#include <iostream>
#include <algorithm>

FlowProblem::FlowProblem()
{

}

FlowProblem::FlowProblem(int taskC, int stationC, int machineC) {
    taskCount = taskC;
    stationCount = stationC;
    machinesPerStation = machineC;

    this->findTechnologicalPredecessors();
}

void FlowProblem::setData(std::vector<double> times,
            std::vector<unsigned int> firstPermutation) {
    currentPermutation.setData(
                this->getOperationsCount(),
                times,
                technologicalPredecessor,
                firstPermutation);
}

unsigned int FlowProblem::getTaskCount() {
    return taskCount;
}

unsigned int FlowProblem::getStationCount() {
    return stationCount;
}

unsigned int FlowProblem::getMachinesPerStation() {
    return machinesPerStation;
}

unsigned int FlowProblem::getOperationsCount() {
    return taskCount * stationCount;
}

unsigned int FlowProblem::getTotalMachineCount() {
    return stationCount * machinesPerStation;
}

//void FlowProblem::setTaskTimes(std::vector<double> times) {
//    taskTimes = times;
//}

//std::vector<double> FlowProblem::getTotalTimes() {
//    // TODO: Przenieść w jakieś lepsze miejsce
//    this ->calculateTotalTimes();
//    this->findCriticalPath();

//    return totalTimes;
//}

std::vector<double> FlowProblem::getTotalTimes() {
    return currentPermutation.getTotalTimes();
}

double FlowProblem::getBestCMax() {
    // TODO: Po napisaniu przestawienia zmienić
    return currentPermutation.getCMax();
}

unsigned int FlowProblem::getBestCMaxPosition() {
    // TODO: Po napisaniu przestawienia zmienić
    return currentPermutation.getCMaxPosition();
}

void FlowProblem::findTechnologicalPredecessors() {
    technologicalPredecessor.clear();

    unsigned int vectorLength = this->getOperationsCount() + 1;

    technologicalPredecessor.assign(vectorLength, 0);

    unsigned int currentStation = 1;

    for (std::vector<unsigned int>::iterator it = technologicalPredecessor.begin() + 1;
         it != technologicalPredecessor.end(); it++, currentStation++) {
        if (currentStation % stationCount != 1) {
            *it = currentStation - 1;
        }
    }
}

void FlowProblem::printPreviousTasks() {
    unsigned int i = 0;

    std::cout << "Poprzednicy technologiczni: " << std::endl;

    for (auto const &task : technologicalPredecessor) {
        std::cout << i << ": " << task << "   ";
        i++;
    }
    std::cout << std::endl;
}

void FlowProblem::printLongerPredecessors() {
    currentPermutation.printLongerPredecessors();
}

void FlowProblem::printCriticalPath() {
    currentPermutation.printCriticalPath();
}

void FlowProblem::printBlockSplit() {
    currentPermutation.printBlockSplit();
}

void FlowProblem::setCriticalPath(std::vector<unsigned int> criticalPath) {
    currentPermutation.setCriticalPath(criticalPath);
}


