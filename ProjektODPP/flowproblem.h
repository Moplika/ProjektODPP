#ifndef FLOWPROBLEM_H
#define FLOWPROBLEM_H

#include <vector>
#include <queue>
#include <list>
#include "station.h"
#include "machine.h"
#include "tabulistelement.h"

enum BlockPosition {
    blockMiddle = 0,
    blockStart = 1,
    blockEnd = 2
};

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

    void setTabuListMaxLength(unsigned int length);

    void findBestPermutation();
    void insertBehind(int elementPosition, int finalPosition);

    double doTabuSearch(unsigned int iterationNb, unsigned int tabuListLength);

    // debug
    void printPreviousTasks();
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();
    void printStationBoundries();
    void printMachineBoundries();
    void printCurrentPermutation();
    void printPositionsInPermutation();
    void printPositionOnMachine();
    void printTabuList();

    void setCriticalPath(std::vector<unsigned int> criticalPath);


private:
    unsigned int taskCount; // n
    unsigned int stationCount; // s
    unsigned int machinesPerStation; // k

    unsigned int tabuListMaxLength;

    //    Permutation currentPermutation;

    void findTechnologicalPredecessors();
    void calculateTotalTimes();
    void findCriticalPath();
    void splitIntoBlocks();
    void findStationBoundries();
    void findMachineBoundries();

    void determinePositionInPermutationAndOnMachine();

    void swapElementPosition(int elementPosition, int finalPosition);
    int findPositionInPermutation(unsigned int element);
    Station findStation(unsigned int element);
    Machine findMachine(unsigned int element);

    void recalculateTimes();
    void findBestPermutationForElement(unsigned int firstPosition,
                                       unsigned int lastPosition,
                                       unsigned int &elementPosition,
                                       double &bestCMax,
                                       unsigned int &bestElementPosition,
                                       unsigned int &movedElement,
                                       int &counter);
    void tryDifferentMachines(Machine machine, Station station,
                              unsigned int &elementPosition,
                              double &bestCMax,
                              unsigned int &bestElementPosition,
                              unsigned int &movedElement,
                              int &counter);
    void setBestSolution(unsigned int movedElement, unsigned int newPosition);

    void findBlockBoundries(std::vector<BlockPosition>::iterator blockSplitIt,
                            int &blockStart, int &blockStop);
    void addTabuListElement(TabuListElement element);

    bool doesFulfillRequirements(unsigned int elementPosition, unsigned int finalPosition);

    std::vector<unsigned int> currentPermutation;
    std::vector<unsigned int> positionInPermutation;
    std::vector<unsigned int> positionOnMachine;

    std::vector<double> taskTimes;

    std::vector<unsigned int> technologicalPredecessor;
    std::vector<unsigned int> longerPredecessor;
    std::vector<Station> stationBoundries;
    std::vector<Machine> machineBoundries;

    std::vector<double> totalTimes;
    std::vector<unsigned int> criticalPath;
    std::vector<BlockPosition> blockSplit;

    std::list<TabuListElement> tabuList;

};




#endif // FLOWPROBLEM_H
