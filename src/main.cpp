/*
 * Handles IO & runs the algorithm
 */

#include <iostream>
#include <regex>
#include "algorithm.h"


using namespace std;

int main(int argc, const char* argv[]) {
    // Validate arguments
    regex arg_regex("[A-Z]+");
    if (argc != 3 || !regex_match(argv[1], arg_regex) || !regex_match(argv[2], arg_regex)) {
        cerr << "Error: Invalid or missing arguments" << endl;
        exit(1);
    }

    // Run specified algorithm for result

    char* result = new char[solver->getMaxResultLength(argv[1], argv[2]) + 1];
    solver->solve(argv[1], argv[2], result);

    // Print result
    cout << result << endl;

    delete result;
    return 0;
}