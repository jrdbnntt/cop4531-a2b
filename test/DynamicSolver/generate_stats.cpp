/*
 * Generates stats
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include "../../src/Dynamic.cpp"
#include "../test.cpp"


int main(int argc, char **argv) {
    AlgorithmSolver* solver = new DynamicSolver();
    vector<Coordinate> results = vector<Coordinate>();
    time_runs(results, solver, atoi(argv[1]), atoi(argv[2]));
    print_runs(results, cout);
}