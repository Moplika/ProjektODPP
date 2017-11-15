#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>
#include "station.h"

class Permutation
{
public:
    Permutation();
    Permutation(unsigned int opCount, std::vector<double> times,
                std::vector<unsigned int> techPredecessor);
    Permutation(unsigned int opCount, std::vector<double> times,
                std::vector<unsigned int> techPredecessor,
                std::vector<unsigned int> firstPermutation);

    void setData(unsigned int opCount, std::vector<double> times,
                 std::vector<unsigned int> techPredecessor,
                 std::vector<unsigned int> firstPermutation);

    void insertInFront(int elementPosition, int finalPosition);
    void findBestPosition(unsigned int elementNumber, Station station);

    unsigned int findElementPosition(unsigned int element);

    void setCurrentPermutation(std::vector<unsigned int> permutation);
    std::vector<unsigned int> getCurrentPermutation();
    unsigned int getOperationsCount();
    std::vector<unsigned int> getCriticalPath();

    std::vector<double> getTotalTimes();
    double getCMax();
    unsigned int getCMaxPosition();



    // debug
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();
    void printCurrentPermutation();

    void setCriticalPath(std::vector<unsigned int> critPath);

private:
    void calculateTotalTimes();
    void findCriticalPath();
    void splitIntoBlocks();
    void findStationBoundries();

    void recalculateTimes();
    void swapElementPosition(int elementPosition, int finalPosition);

    bool isPartOfCriticalPath(unsigned int element);

    unsigned int operationCount;

    std::vector<unsigned int> currentPermutation;

    std::vector<double> taskTimes;
    std::vector<Station> stationBoundries;
    std::vector<unsigned int> technologicalPredecessor;
    std::vector<unsigned int> longerPredecessor;

    std::vector<double> totalTimes;
    std::vector<unsigned int> criticalPath;
    std::vector<unsigned int> blockSplit;
};



#endif // PERMUTATION_H
