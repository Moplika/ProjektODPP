#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>

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

    void setCurrentPermutation(std::vector<unsigned int> permutation);
    std::vector<unsigned int> getCurrentPermutation();
    unsigned int getOperationsCount();

    std::vector<double> getTotalTimes();
    double getCMax();
    unsigned int getCMaxPosition();

    // debug
    void printLongerPredecessors();
    void printCriticalPath();
    void printBlockSplit();

    void setCriticalPath(std::vector<unsigned int> critPath);

private:
    void calculateTotalTimes();
    void findCriticalPath();
    void splitIntoBlocks();

    unsigned int operationCount;

    std::vector<unsigned int> currentPermutation;

    std::vector<double> taskTimes;
    std::vector<unsigned int> technologicalPredecessor;
    std::vector<unsigned int> longerPredecessor;

    std::vector<double> totalTimes;
    std::vector<unsigned int> criticalPath;
    std::vector<unsigned int> blockSplit;
};

#endif // PERMUTATION_H
