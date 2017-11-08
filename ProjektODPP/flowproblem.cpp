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

void FlowProblem::setCurrentPermutation(std::vector<unsigned int> permutation) {
    currentPermutation = permutation;
}

void FlowProblem::setTaskTimes(std::vector<double> times) {
    taskTimes = times;
}

std::vector<double> FlowProblem::getTotalTimes() {
    // TODO: Przenieść w jakieś lepsze miejsce
    this ->calculateTotalTimes();
    this->findCriticalPath();

    return totalTimes;
}

double FlowProblem::getCMax() {
    return *(std::max_element(totalTimes.begin(), totalTimes.end()));
}

unsigned int FlowProblem::getCMaxPosition() {
    auto cMaxIt = std::max_element(totalTimes.begin(), totalTimes.end());

    return std::distance(totalTimes.begin(), cMaxIt);
}

void FlowProblem::calculateTotalTimes() {
    unsigned int operationCount = getOperationsCount();

    totalTimes.clear();
    totalTimes.assign(operationCount + 1, 0.0);

    longerPredecessor.clear();
    longerPredecessor.assign(operationCount + 1, 0.0);

    unsigned int previousOnMachine = 0;

    for (auto const &taskIndex : currentPermutation) {
        if (taskIndex != 0) {
            unsigned int previousTask = technologicalPredecessor.at(taskIndex);
            double previousTaskTime = totalTimes.at(previousTask);
            double machineFreeTime = totalTimes.at(previousOnMachine);

            double currentTaskTime = taskTimes.at(taskIndex);

            if (machineFreeTime >= previousTaskTime) {
                totalTimes.at(taskIndex) = machineFreeTime + currentTaskTime;
                longerPredecessor.at(taskIndex) = previousOnMachine;
            } else {
                totalTimes.at(taskIndex) = previousTaskTime + currentTaskTime;
                longerPredecessor.at(taskIndex) = previousTask;
            }

        }
        previousOnMachine = taskIndex;
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
    int i = 0;

    std::cout << "Longer predecessors: " << std::endl;
    for (auto element : longerPredecessor) {
        std::cout << i << ": " << element << "   ";
        i++;
    }
    std::cout << std::endl;
}

void FlowProblem::printCriticalPath() {
    std::cout << "Sciezka krytyczna: " << std::endl;
    for (auto element : criticalPath) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void FlowProblem::printBlockSplit() {
    std::cout << "Podział na bloki: " << std::endl;
    for (auto element : blockSplit) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void FlowProblem::setCriticalPath(std::vector<unsigned int> critPath) {
    criticalPath = critPath;
    this->splitIntoBlocks();
}

void FlowProblem::findCriticalPath() {
    unsigned int previousElement = this->getCMaxPosition();

    while (previousElement != 0) {
        criticalPath.push_back(previousElement);

        previousElement = longerPredecessor.at(previousElement);
    }

    std::reverse(criticalPath.begin(), criticalPath.end());
    this->splitIntoBlocks();
}

void FlowProblem::splitIntoBlocks() {
    int criticalPathLength = criticalPath.size();

    blockSplit.clear();
    blockSplit.assign(criticalPathLength, 0.0);

    unsigned int previousElement = criticalPath.front();
    int i = 0;

    for (auto element : criticalPath) {
        if (element - previousElement == 1) {
            blockSplit.at(i-1) = 2;
            blockSplit.at(i) = 1;
        }
        previousElement = element;
        i++;
    }

    blockSplit.front() = 1;
    blockSplit.back() = 2;

}
