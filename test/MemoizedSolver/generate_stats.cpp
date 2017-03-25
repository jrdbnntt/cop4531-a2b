/*
 * Generates stats
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include "../../src/Memoized.cpp"
#include "../test.cpp"


int main(int argc, char **argv) {
    AlgorithmSolver* solver = new MemoizedSolver();
    vector<Coordinate> results = vector<Coordinate>();
    time_runs(results, solver, atoi(argv[1]), atoi(argv[2]));
    print_runs(results, cout);
}