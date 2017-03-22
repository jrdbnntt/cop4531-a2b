#include <iostream>
#include "../../src/Dynamic.cpp"
#include "../test.cpp"


int main(int argc, char **argv) {
    AlgorithmSolver* solver = new DynamicSolver();
    for (int i = 0; i < simple_cases.size(); ++i) {
        cout << " Checking simple case "<< i << " ";
        simple_cases[i].printSizeSummary(cout);
        cout << " ... ";
        simple_cases[i].test(solver);
        cout << " SUCCESS" << endl;
    }
}