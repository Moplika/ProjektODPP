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

    this->findStationBoundries();
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

std::vector<double> FlowProblem::getTotalTimes() {
    return currentPermutation.getTotalTimes();
}

Permutation FlowProblem::getCurrentPermutation() {
    return currentPermutation;
}

std::vector<Station> FlowProblem::getStationBoundries() {
    return stationBoundries;
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

void FlowProblem::printStationBoundries() {
    std::cout << "Podzial na stacje: " << std::endl;
    for (auto station : stationBoundries) {
        std::cout << "Stanowisko " << station.id << " - poczatek: " << station.firstPosition
                  << ", koniec: " << station.lastPosition << std::endl;
    }
}

void FlowProblem::printCurrentPermutation() {
    currentPermutation.printCurrentPermutation();
}

void FlowProblem::setCriticalPath(std::vector<unsigned int> criticalPath) {
    currentPermutation.setCriticalPath(criticalPath);
}

void FlowProblem::findStationBoundries() {
    stationBoundries.clear();

    auto permutation = currentPermutation.getCurrentPermutation();

    unsigned int elementIndex = 1;
    unsigned int zeroCount = 0;
    unsigned int stationCount = 1;
    unsigned int firstElement = 1;

    for (auto it = permutation.begin() + 1; it != permutation.end(); it++, elementIndex++) {
        if (*it == 0) {
            zeroCount++;

            if (zeroCount % machinesPerStation == 0) {
                unsigned int lastElement = elementIndex - 1;
                Station newStation(stationCount, firstElement, lastElement);

                stationBoundries.push_back(newStation);
                stationCount++;

                firstElement = elementIndex + 1;
            }
        }
    }
}
