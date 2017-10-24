#include "flowproblem.h"

#include <iostream>

FlowProblem::FlowProblem()
{

}

FlowProblem::FlowProblem(int taskC, int stationC, int machineC) {
    taskCount = taskC;
    stationCount = stationC;
    machinesPerStation = machineC;

    this->findPreviousTasks();
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

void FlowProblem::findPreviousTasks() {
    previousTasks.clear();

    unsigned int vectorLength = this->getOperationsCount() + 1;

    previousTasks.assign(vectorLength, 0);

    unsigned int currentStation = 1;

    for (std::vector<unsigned int>::iterator it = previousTasks.begin() + 1;
         it != previousTasks.end(); it++, currentStation++) {
        if (currentStation % stationCount != 1) {
            *it = currentStation - 1;
        }
    }


}

void FlowProblem::printPreviousTasks() {
    unsigned int i = 0;

    std::cout << "Poprzednicy technologiczni: " << std::endl;

//    for (std::vector<unsigned int>::iterator it = previousTasks.begin();
//         it != previousTasks.end(); it++, i++) {
//        std::cout << i << ": " << *it << std::endl;
//    }

    for (auto const &task : previousTasks) {
        std::cout << i << ": " << task << std::endl;
        i++;
    }
}

void FlowProblem::setCurrentPermutation(std::vector<unsigned int> permutation) {
    currentPermutation = permutation;
}

void FlowProblem::setTaskTimes(std::vector<double> times) {
    taskTimes = times;
}

std::vector<double> FlowProblem::getTotalTimes() {
    unsigned int operationCount = getOperationsCount();
    std::vector<double> totalTimes(operationCount + 1, 0.0);

    unsigned int previousOnMachine = 0;

    for (auto const &taskIndex : currentPermutation) {
        if (taskIndex != 0) {
            unsigned int previousTask = previousTasks.at(taskIndex);
            double previousTaskTime = totalTimes.at(previousTask);
            double machineFreeTime = totalTimes.at(previousOnMachine);

            double currentTaskTime = taskTimes.at(taskIndex);

            totalTimes.at(taskIndex) = std::max(previousTaskTime, machineFreeTime)
                    + currentTaskTime;
        }
        previousOnMachine = taskIndex;
    }

    return totalTimes;
}

