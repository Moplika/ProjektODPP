#include "flowproblem.h"

#include <iostream>
#include <algorithm>

// TODO: Naprawić podział na stacje/maszyny, jeśli permutacja nie kończy się na 0
// Może przy wczytywaniu danych?

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
    currentPermutation = firstPermutation;
    taskTimes = times;

    if (currentPermutation.back() != 0) {
        currentPermutation.push_back(0);
    }

    this->findStationBoundries();

    this->recalculateTimes();
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
    return totalTimes;
}

std::vector<Station> FlowProblem::getStationBoundries() {
    return stationBoundries;
}

double FlowProblem::getCMax() {
    return *(std::max_element(totalTimes.begin(), totalTimes.end()));
}

unsigned int FlowProblem::getCMaxPosition() {
    auto cMaxIt = std::max_element(totalTimes.begin(), totalTimes.end());

    return std::distance(totalTimes.begin(), cMaxIt);
}

void FlowProblem::setCriticalPath(std::vector<unsigned int> critPath) {
    criticalPath = critPath;
    this->splitIntoBlocks();
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

void FlowProblem::findStationBoundries() {
    stationBoundries.clear();

    unsigned int elementIndex = 1;
    unsigned int zeroCount = 0;
    unsigned int stationCount = 1;
    unsigned int firstElement = 1;

    for (auto it = currentPermutation.begin() + 1; it != currentPermutation.end();
         it++, elementIndex++) {
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

void FlowProblem::findMachineBoundries() {
    machineBoundries.clear();

    unsigned int elementIndex = 1;
    unsigned int zeroCount = 0;
    unsigned int machineCount = 1;
    unsigned int firstElement = 1;

    for (auto it = currentPermutation.begin() + 1; it != currentPermutation.end();
         it++, elementIndex++) {
        if (*it == 0) {
            zeroCount++;

            unsigned int lastElement = elementIndex - 1;
            Machine newMachine(machineCount, firstElement, lastElement);
            machineBoundries.push_back(newMachine);
            machineCount++;

            firstElement = elementIndex + 1;
        }
    }
}

void FlowProblem::calculateTotalTimes() {
    unsigned int operationCount = this->getOperationsCount();

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

void FlowProblem::findCriticalPath() {
    criticalPath.clear();

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
    blockSplit.assign(criticalPathLength, BlockPosition::blockMiddle);

    unsigned int previousElement = criticalPath.front();
    int i = 0;

    for (auto element : criticalPath) {
        if (element - previousElement == 1) {
            blockSplit.at(i-1) = BlockPosition::blockEnd;
            blockSplit.at(i) = BlockPosition::blockStart;
        }
        previousElement = element;
        i++;
    }

    blockSplit.front() = BlockPosition::blockStart;
    blockSplit.back() = BlockPosition::blockEnd;
}

void FlowProblem::swapElementPosition(int elementPosition, int finalPosition) {
    unsigned int element = currentPermutation.at(elementPosition);

    auto elementIt = currentPermutation.begin() + elementPosition;
    currentPermutation.erase(elementIt);

    auto finalIt = currentPermutation.begin() + finalPosition;
    currentPermutation.insert(finalIt, element);
}

void FlowProblem::insertBehind(int elementPosition, int finalPosition) {
    this->swapElementPosition(elementPosition, finalPosition);
    this->recalculateTimes();
}

void FlowProblem::findBestPermutation() {
    int tempCnt = 0;

    auto originalPermutation = currentPermutation;

    double bestCMax = this->getCMax();
    unsigned int movedElementPosition = 0;
    unsigned int bestElementPosition = 0;

    auto blockSplitIt = blockSplit.begin();

    for (auto critPathElement : criticalPath) {

        // Debug
        //        std::cout << "Przestawiamy " << critPathElement << std::endl;

        unsigned int elementPosition = this->findPositionInPermutation(critPathElement);
        Station station = this->findStation(critPathElement);
        Machine machine = this->findMachine(critPathElement);
        unsigned int blockSign = *blockSplitIt;

        unsigned int firstPosition = 0;
        unsigned int lastPosition = 0;

        switch (blockSign) {
        case BlockPosition::blockStart:
            // Przenoszenie przed blok na maszynie
            firstPosition = machine.firstPosition;
            lastPosition = elementPosition - 1;

            this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                                bestCMax, bestElementPosition, movedElementPosition, tempCnt);

            // Inne maszyny
            this->tryDifferentMachines(machine, station, elementPosition, bestCMax, bestElementPosition,
                                       movedElementPosition, tempCnt);
            break;

        case BlockPosition::blockEnd:
            // Przenoszenie za blok na maszynie
            firstPosition = elementPosition + 1;
            lastPosition = machine.lastPosition;
            this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                                bestCMax, bestElementPosition, movedElementPosition, tempCnt);
            // Inne maszyny
            this->tryDifferentMachines(machine, station, elementPosition, bestCMax,
                                       bestElementPosition, movedElementPosition, tempCnt);
            break;

        case BlockPosition::blockMiddle:
            int firstInBlock;
            int lastInBlock;

            this->findBlockBoundries(blockSplitIt, firstInBlock, lastInBlock);

            // Ta sama maszyna, przed blokiem
            firstPosition = machine.firstPosition;
            lastPosition = std::max(firstInBlock, machine.firstPosition);

            this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                                bestCMax, bestElementPosition, movedElementPosition, tempCnt);
            // Ta sama maszyna, za blokiem
            firstPosition = std::min(lastInBlock + 1, machine.lastPosition);
            lastPosition = machine.lastPosition;

            this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                                bestCMax, bestElementPosition, movedElementPosition, tempCnt);
            // Inne maszyny
            this->tryDifferentMachines(machine, station, elementPosition, bestCMax,
                                       bestElementPosition, movedElementPosition, tempCnt);
            break;

        default:
            firstPosition = station.firstPosition;
            lastPosition = station.lastPosition;

            this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                                bestCMax, bestElementPosition, movedElementPosition, tempCnt);
        }
        currentPermutation = originalPermutation;
        blockSplitIt++;
    }
    this->setBestSolution(movedElementPosition, bestElementPosition);

    std::cout << "Wykonano " << tempCnt << " iteracji dla sciezki krytycznej o "
              << criticalPath.size() << " elementach"<< std::endl;
}

void FlowProblem::tryDifferentMachines(Machine machine, Station station, unsigned int &elementPosition,
                                       double &bestCMax, unsigned int &bestElementPosition,
                                       unsigned int &movedElement, int &counter) {
    // Przenoszenie na inną maszynę - wcześniejsze maszyny
    unsigned int firstPosition = station.firstPosition;
    unsigned int lastPosition = machine.firstPosition - 1;

    this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                        bestCMax, bestElementPosition, movedElement, counter);

    // Przenoszenie na inną maszynę - następne maszyny
    firstPosition = machine.lastPosition + 1;
    lastPosition = station.lastPosition;

    this->findBestPermutationForElement(firstPosition, lastPosition, elementPosition,
                                        bestCMax, bestElementPosition, movedElement, counter);
}

void FlowProblem::findBestPermutationForElement(unsigned int firstPosition,
                                                unsigned int lastPosition,
                                                unsigned int &elementPosition,
                                                double &bestCMax,
                                                unsigned int &bestElementPosition,
                                                unsigned int &movedElement,
                                                int &counter) {
    if (elementPosition == lastPosition || firstPosition > lastPosition) {
        return;

    }
    for (unsigned int position = firstPosition;
         position <= lastPosition; position++) {

        if (this->doesFulfillRequirements(elementPosition, position)) {
            this->swapElementPosition(elementPosition, position);
            this->calculateTotalTimes();

            if (this->getCMax() < bestCMax) {
                bestCMax = this->getCMax();
                bestElementPosition = position;
                movedElement = currentPermutation.at(position);
            }
            elementPosition = position;
        }



        //Debug
        //        this->printCurrentPermutation();
        //        std::cout << "Cmax: " << this->getCMax() << std::endl;

        counter++;
    }
}

void FlowProblem::setBestSolution(unsigned int movedElement, unsigned int newPosition) {
    if (movedElement == 0) {
        this->recalculateTimes();
        return;
    }

    // Dodanie nowych ograniczeń
    unsigned int previousMachine = this->findMachine(movedElement).id;
    unsigned int elementOnNewPosition = currentPermutation.at(newPosition);

    unsigned int newMachine;
    if (elementOnNewPosition == 0) {
        // Potrzebujemy dostać maszynę, za którą wstawiamy, więc jeśli wstawiamy za 0, to musimy tutaj
        // wziąć następny element z permutacji (maszyna dla 0 jest nieokreślona)
        unsigned int nextElementOnMachine = currentPermutation.at(newPosition+1);
        newMachine = this->findMachine(nextElementOnMachine).id;
    } else {
        newMachine = this->findMachine(elementOnNewPosition).id;
    }

    unsigned int movedElementPosition = this->findPositionInPermutation(movedElement);

    unsigned int previousElement = currentPermutation.at(movedElementPosition - 1);
    unsigned int nextElement = currentPermutation.at(movedElementPosition + 1);

    if (previousMachine == newMachine) { // Przenoszenie wewnątrz jednej maszyny
        if (movedElementPosition < newPosition) { // Przenoszenie przed blok
            TabuListElement newElement (previousMachine, movedElement, nextElement);
            this->addTabuListElement(newElement);
        } else if (movedElementPosition > newPosition) { // Przenoszenie za blok
            TabuListElement newElement (previousMachine, previousElement, movedElement);
            this->addTabuListElement(newElement);
        }
    } else { // Przenoszenie na inną maszynę
        TabuListElement newElement (previousMachine, previousElement, movedElement);
        this->addTabuListElement(newElement);
        newElement = TabuListElement(previousMachine, movedElement, nextElement);
        this->addTabuListElement(newElement);
    }
    // Przeniesienie elementu
    this->swapElementPosition(movedElementPosition, newPosition);
    this->recalculateTimes();
}

int FlowProblem::findPositionInPermutation(unsigned int element) {
    return positionInPermutation.at(element);
}

Station FlowProblem::findStation(unsigned int element) {
    int elementPosition = this->findPositionInPermutation(element);

    for (auto station : stationBoundries) {
        if (elementPosition >= station.firstPosition && elementPosition <= station.lastPosition) {
            return station;
        }
    }
    // Nigdy nie powinno tutaj dojść
    return stationBoundries.front();
}

Machine FlowProblem::findMachine(unsigned int element) {
    unsigned int machineID = positionOnMachine.at(element);
    return machineBoundries.at(machineID-1);
}

void FlowProblem::findBlockBoundries(std::vector<BlockPosition>::iterator blockSplitIt,
                                     int &blockStart, int &blockStop) {
    unsigned int elementIndex = std::distance(blockSplit.begin(), blockSplitIt);

    unsigned int index = elementIndex;
    for (auto it = blockSplitIt; it != blockSplit.end(); it++, index++) {
        if (*it == 2) {
            blockStop = this->findPositionInPermutation(criticalPath.at(index));
            break;
        }
    }

    index = elementIndex;
    for (auto it = blockSplitIt; it != blockSplit.begin()-1; it--, index--) {
        if (*it == 1) {
            blockStart = this->findPositionInPermutation(criticalPath.at(index));
            break;
        }
    }
}

void FlowProblem::recalculateTimes() {
    this->calculateTotalTimes();
    this->findCriticalPath();
    this->determinePositionInPermutationAndOnMachine();
    this->findMachineBoundries();
}

void FlowProblem::determinePositionInPermutationAndOnMachine() {
    positionInPermutation.clear();
    positionInPermutation.assign(getOperationsCount()+1, 0);

    positionOnMachine.clear();
    positionOnMachine.assign(getOperationsCount()+1, 0);

    unsigned int i = 0;
    unsigned int ms = 0;

    for (auto element : currentPermutation) {
        positionInPermutation.at(element) = i;

        if (element == 0) {
            ms++;
        } else {
            positionOnMachine.at(element) = ms;
        }
        i++;
    }
}

void FlowProblem::addTabuListElement(TabuListElement element) {
    if (element.frontElement == 0 || element.backElement == 0)
        return;

    tabuList.push_back(element);

    while (tabuList.size() > tabuListMaxLength) {
        tabuList.pop_front();
    }
}

bool FlowProblem::doesFulfillRequirements(unsigned int elementPosition, unsigned int newPosition) {
//        return true;

    unsigned int element = currentPermutation.at(elementPosition);


    unsigned int newElementMachine;

    if (currentPermutation.at(newPosition) == 0) {
        newElementMachine = this->findMachine(currentPermutation.at(newPosition + 1)).id;
    } else {
        newElementMachine = this->findMachine(currentPermutation.at(newPosition)).id;
    }

    for (auto tabuElement : tabuList) {
        unsigned int frontElementMachine = this->findMachine(tabuElement.frontElement).id;
        unsigned int backElementMachine = this->findMachine(tabuElement.backElement).id;

        if (element == tabuElement.frontElement) {
            if (newElementMachine == backElementMachine) {
                unsigned int backElementPosition = this->findPositionInPermutation(tabuElement.backElement);
                if (newPosition > backElementPosition) {
                    //Debug
//                    std::cout << "Niespelnione ograniczenie! Na maszynie " << tabuElement.machineId << " element "
//                              << tabuElement.frontElement << " powinien byc przed " << tabuElement.backElement << std::endl;

                    return false;
                }
            }
        } else if (element == tabuElement.backElement) {
            if (newElementMachine == backElementMachine) {
                unsigned int frontElementPosition = this->findPositionInPermutation(tabuElement.frontElement);
                if (frontElementPosition > newPosition) {
                    //Debug
//                    std::cout << "Niespelnione ograniczenie! Na maszynie " << tabuElement.machineId << " element "
//                              << tabuElement.frontElement << " powinien byc przed " << tabuElement.backElement << std::endl;

                    return false;
                }
            }

        } else if (frontElementMachine == backElementMachine) {
            unsigned int frontElementPosition = this->findPositionInPermutation(tabuElement.frontElement);
            unsigned int backElementPosition = this->findPositionInPermutation(tabuElement.backElement);

            if (frontElementPosition > backElementPosition) {
                //Debug
//                std::cout << "Niespelnione ograniczenie! Na maszynie " << tabuElement.machineId << " element "
//                          << tabuElement.frontElement << " powinien byc przed " << tabuElement.backElement << std::endl;

                return false;
            }
        }
    }
    return true;
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
    std::cout << "Podzial na bloki: " << std::endl;
    for (auto element : blockSplit) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void FlowProblem::printStationBoundries() {
    std::cout << "Podzial na stacje: " << std::endl;
    for (auto station : stationBoundries) {
        std::cout << "Stanowisko " << station.id << " - poczatek: " << station.firstPosition
                  << ", koniec: " << station.lastPosition << std::endl;
    }
}

void FlowProblem::printMachineBoundries() {
    std::cout << "Podzial na maszyny: " << std::endl;
    for (auto station : machineBoundries) {
        std::cout << "Maszyna " << station.id << " - poczatek: " << station.firstPosition
                  << ", koniec: " << station.lastPosition << std::endl;
    }
}

void FlowProblem::printCurrentPermutation() {
    //    std::cout << "Aktualna permutacja: " << std::endl;
    for (auto element : currentPermutation) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void FlowProblem::printPositionsInPermutation() {
    std::cout << "Pozycje elementow w permutacji: " << std::endl;

    int i = 0;
    for (auto element : positionInPermutation) {
        std::cout << i << ": " << element << "   ";
        i++;
    }
    std::cout << std::endl;
}

void FlowProblem::printPositionOnMachine() {
    std::cout << "Pozycje elementow na maszynie: " << std::endl;

    int i = 0;
    for (auto element : positionOnMachine) {
        std::cout << i << ": " << element << "   ";
        i++;
    }
    std::cout << std::endl;
}

void FlowProblem::printTabuList() {
    std::cout << "Tabu list: " << std::endl;

    for (auto element : tabuList) {
        std::cout << "Maszyna: " << element.machineId << ", pierwsze: " << element.frontElement
                  << ", drugie: " << element.backElement << std::endl;
    }
}
