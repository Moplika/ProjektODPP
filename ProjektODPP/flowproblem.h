#ifndef FLOWPROBLEM_H
#define FLOWPROBLEM_H

#include <vector>
#include "permutation.h"
#include "station.h"


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

    Permutation getCurrentPermutation();
    std::vector<Station> getStationBoundries();

    std::vector<double> getTotalTimes();
    double getBestCMax();
    unsigned int getBestCMaxPosition();

    // debug
    void printPreviousTasks();
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();
    void printStationBoundries();
    void printCurrentPermutation();

    void setCriticalPath(std::vector<unsigned int> criticalPath);

private:
    unsigned int taskCount; // n
    unsigned int stationCount; // s
    unsigned int machinesPerStation; // k

    Permutation currentPermutation;

    void findTechnologicalPredecessors();
    void findStationBoundries();

    std::vector<unsigned int> technologicalPredecessor;
    std::vector<Station> stationBoundries;

};



#endif // FLOWPROBLEM_H
