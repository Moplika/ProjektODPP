#ifndef FLOWPROBLEM_H
#define FLOWPROBLEM_H

#include <vector>


class FlowProblem
{
public:
    FlowProblem();
    FlowProblem(int taskC, int stationC, int machineC);

    unsigned int getTaskCount();
    unsigned int getStationCount();
    unsigned int getMachinesPerStation();
    unsigned int getOperationsCount();
    unsigned int getTotalMachineCount();

    std::vector<double> getTotalTimes();
    double getCMax();
    unsigned int getCMaxPosition();

    // debug
    void printPreviousTasks();
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();

    void setCurrentPermutation(std::vector<unsigned int> permutation);
    void setTaskTimes(std::vector<double> times);
    void setCriticalPath(std::vector<unsigned int> criticalPath);

private:
    unsigned int taskCount; // n
    unsigned int stationCount; // s
    unsigned int machinesPerStation; // k

    void findTechnologicalPredecessors();
    void calculateTotalTimes();
    void findCriticalPath();
    void splitIntoBlocks();

    std::vector<unsigned int> technologicalPredecessor;
    std::vector<unsigned int> longerPredecessor;

    std::vector<double> totalTimes;
    std::vector<unsigned int> criticalPath;
    std::vector<unsigned int> blockSplit;

    std::vector<double> taskTimes;
    std::vector<unsigned int> currentPermutation;

};

#endif // FLOWPROBLEM_H
