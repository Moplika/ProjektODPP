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

    // debug
    void printPreviousTasks();
    void setCurrentPermutation(std::vector<unsigned int> permutation);
    void setTaskTimes(std::vector<double> times);

private:
    unsigned int taskCount; // n
    unsigned int stationCount; // s
    unsigned int machinesPerStation; // k

    void findPreviousTasks();

    std::vector<unsigned int> previousTasks;
    std::vector<double> taskTimes;
    std::vector<unsigned int> currentPermutation;
};

#endif // FLOWPROBLEM_H
