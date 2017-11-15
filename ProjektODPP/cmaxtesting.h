#ifndef CMAXTESTING_H
#define CMAXTESTING_H

#include <vector>

bool cMaxTest(unsigned int n, unsigned int s, unsigned int ms,
              double times[], unsigned int permutation[],
              double expectedCMax, double expectedTimes[]);

void mojPrzykladTest();
void criticalPathTest();

void permutationSingleSwapTest();
void permutationSwapingTest();
void stationBoundriesTest();

void permutationSwapingTest15_2();

bool test20_5();
bool test20_10();
bool test20_20();
bool test50_5();
bool test50_10();
bool test50_20();
bool test100_5();
bool test100_10();

#endif // CMAXTESTING_H
