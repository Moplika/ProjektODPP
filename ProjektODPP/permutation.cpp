#include "permutation.h"

#include <algorithm>
#include <iostream>

Permutation::Permutation()
{
    operationCount = 0;
}

Permutation::Permutation(unsigned int opCount,
            std::vector<double> times,
            std::vector<unsigned int> techPredecessor) {
    operationCount = opCount;
    taskTimes = times;
    technologicalPredecessor = techPredecessor;
}

Permutation::Permutation(unsigned int opCount,
            std::vector<double> times,
            std::vector<unsigned int> techPredecessor,
            std::vector<unsigned int> firstPermutation) {
    setData(opCount, times, techPredecessor, firstPermutation);
}

void Permutation::setData(unsigned int opCount,
            std::vector<double> times,
            std::vector<unsigned int> techPredecessor,
            std::vector<unsigned int> firstPermutation) {
    operationCount = opCount;
    taskTimes = times;
    technologicalPredecessor = techPredecessor;
    currentPermutation = firstPermutation;

    this->calculateTotalTimes();
    this->findCriticalPath();
}

void Permutation::setCurrentPermutation(std::vector<unsigned int> permutation) {
    currentPermutation = permutation;
}

std::vector<unsigned int> Permutation::getCurrentPermutation() {
    return currentPermutation;
}

unsigned int Permutation::getOperationsCount() {
    return operationCount;
}

std::vector<double> Permutation::getTotalTimes() {
    return totalTimes;
}

double Permutation::getCMax() {
    return *(std::max_element(totalTimes.begin(), totalTimes.end()));
}

unsigned int Permutation::getCMaxPosition() {
    auto cMaxIt = std::max_element(totalTimes.begin(), totalTimes.end());

    return std::distance(totalTimes.begin(), cMaxIt);
}

void Permutation::calculateTotalTimes() {
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

void Permutation::findCriticalPath() {
    unsigned int previousElement = this->getCMaxPosition();

    while (previousElement != 0) {
        criticalPath.push_back(previousElement);

        previousElement = longerPredecessor.at(previousElement);
    }

    std::reverse(criticalPath.begin(), criticalPath.end());
    this->splitIntoBlocks();
}

void Permutation::splitIntoBlocks() {
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

void Permutation::printLongerPredecessors() {
    int i = 0;

    std::cout << "Longer predecessors: " << std::endl;
    for (auto element : longerPredecessor) {
        std::cout << i << ": " << element << "   ";
        i++;
    }
    std::cout << std::endl;
}

void Permutation::printCriticalPath() {
    std::cout << "Sciezka krytyczna: " << std::endl;
    for (auto element : criticalPath) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void Permutation::printBlockSplit() {
    std::cout << "Podział na bloki: " << std::endl;
    for (auto element : blockSplit) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void Permutation::setCriticalPath(std::vector<unsigned int> critPath) {
    criticalPath = critPath;
    this->splitIntoBlocks();
}
