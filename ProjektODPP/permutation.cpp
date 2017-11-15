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
    std::cout << "Podzial na bloki: " << std::endl;
    for (auto element : blockSplit) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void Permutation::printCurrentPermutation() {
    std::cout << "Aktualna permutacja: " << std::endl;
    for (auto element : currentPermutation) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void Permutation::setCriticalPath(std::vector<unsigned int> critPath) {
    criticalPath = critPath;
    this->splitIntoBlocks();
}

void Permutation::recalculateTimes() {
    this->calculateTotalTimes();
    this->findCriticalPath();
}

void Permutation::swapElementPosition(int elementPosition, int finalPosition) {
    unsigned int element = currentPermutation.at(elementPosition);

    auto elementIt = currentPermutation.begin() + elementPosition;
    currentPermutation.erase(elementIt);

    auto finalIt = currentPermutation.begin() + finalPosition;// - 1; // -1 Bo chcemy, żeby wstawiał przed
    currentPermutation.insert(finalIt, element);
}

void Permutation::insertInFront(int elementPosition, int finalPosition) {
    this->swapElementPosition(elementPosition, finalPosition);
    this->recalculateTimes();
}

void Permutation::findBestPosition(unsigned int elementNumber, Station station) {
    if (!isPartOfCriticalPath(elementNumber)) {
        std::cout << "Wybrany element nie nalezy do sciezki krytycznej!" << std::endl;
        return;
    }

    unsigned int elementPosition = this->findElementPosition(elementNumber);

//    auto originalPermutation = currentPermutation;

    double bestCMax = this->getCMax();
    auto bestPermutation = currentPermutation;

    for (unsigned int position = station.firstPosition;
         position <= station.lastPosition; position++) {
        this->swapElementPosition(elementPosition, position);
        this->calculateTotalTimes();

        if (this->getCMax() < bestCMax) {
            bestCMax = this->getCMax();
            bestPermutation = currentPermutation;
        }
        elementPosition = position;

        //Debug
        this->printCurrentPermutation();
        std::cout << "Cmax: " << this->getCMax() << std::endl;
    }

    currentPermutation = bestPermutation;
    this->recalculateTimes();
}

bool Permutation::isPartOfCriticalPath(unsigned int element) {
    for (auto critPathElement : criticalPath) {
        if (critPathElement == element) {
            return true;
        }
    }
    return false;
}

unsigned int Permutation::findElementPosition(unsigned int element) {
    unsigned int position = 0;

    for (auto permutationElement : currentPermutation) {
        if (permutationElement == element) {
            return position;
        }
        position++;
    }

    return 0;
}
