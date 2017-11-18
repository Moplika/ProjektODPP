#ifndef FLOWPROBLEM_H
#define FLOWPROBLEM_H

#include <vector>
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

    std::vector<Station> getStationBoundries();

    std::vector<double> getTotalTimes();
    double getCMax();
    unsigned int getCMaxPosition();

    void findBestPermutation();
    void insertBehind(int elementPosition, int finalPosition);

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

    //    Permutation currentPermutation;

    void findTechnologicalPredecessors();
    void calculateTotalTimes();
    void findCriticalPath();
    void splitIntoBlocks();
    void findStationBoundries();

    void swapElementPosition(int elementPosition, int finalPosition);
    unsigned int findPositionInPermutation(unsigned int element);
    Station findStation(unsigned int element);

    void recalculateTimes();

    std::vector<unsigned int> currentPermutation;
    std::vector<double> taskTimes;

    std::vector<unsigned int> technologicalPredecessor;
    std::vector<unsigned int> longerPredecessor;
    std::vector<Station> stationBoundries;

    std::vector<double> totalTimes;
    std::vector<unsigned int> criticalPath;
    std::vector<unsigned int> blockSplit;

};



#endif // FLOWPROBLEM_H
