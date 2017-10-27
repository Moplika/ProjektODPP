#ifndef FLOWPROBLEMDATAREADER_H
#define FLOWPROBLEMDATAREADER_H

#include "flowproblem.h"

#include <string>

FlowProblem readFlowProblem(std::string filename);
void readSolution(std::string filename, double &expectedCmax,
                  std::vector<double> &expectedTimes);


#endif // FLOWPROBLEMDATAREADER_H
