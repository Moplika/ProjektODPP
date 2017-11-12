#ifndef FLOWPROBLEM_H
#define FLOWPROBLEM_H

#include <vector>
#include "permutation.h"


class FlowProblem
{
public:
    FlowProblem();
    FlowProblem(int taskC, int stationC, int machineC);

    void setData(std::vector<double> times,
                 std::vector<unsigned int> firstPermutation);

    unsigned int getTaskCount();
    unsigned int getStationCount();
    unsigned int getMachinesPerStation();
    unsigned int getOperationsCount();
    unsigned int getTotalMachineCount();

    std::vector<double> getTotalTimes();
    double getBestCMax();
    unsigned int getBestCMaxPosition();

    // debug
    void printPreviousTasks();
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();

//    void setCurrentPermutation(std::vector<unsigned int> permutation);
//    void setTaskTimes(std::vector<double> times);
    void setCriticalPath(std::vector<unsigned int> criticalPath);

private:
    unsigned int taskCount; // n
    unsigned int stationCount; // s
    unsigned int machinesPerStation; // k

    Permutation currentPermutation;

    void findTechnologicalPredecessors();
//    void calculateTotalTimes();
//    void findCriticalPath();
//    void splitIntoBlocks();

    std::vector<unsigned int> technologicalPredecessor;
//    std::vector<unsigned int> longerPredecessor;

//    std::vector<double> totalTimes;
//    std::vector<unsigned int> criticalPath;
//    std::vector<unsigned int> blockSplit;

//    std::vector<double> taskTimes;
//    std::vector<unsigned int> currentPermutation;

};

#endif // FLOWPROBLEM_H
