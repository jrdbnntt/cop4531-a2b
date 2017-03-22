/*
 * Handles IO & runs the algorithm
 */

#include <iostream>
#include <cstring>
#include "algorithm.h"

using namespace std;

/**
 * Validates arg against [A-Z]+
 * @param arg
 * @return
 */
bool checkArg(const char * arg) {
    int len = (int) strlen(arg);
    char c;
    for (int i = 0; i < len; ++i) {
        c = arg[i];
        if (c < 'A' || c > 'Z') {
            return false;
        }
    }
    return true;
}

int main(int argc, const char* argv[]) {
    // Validate arguments
    if (argc != 3 || !checkArg(argv[1]) || !checkArg(argv[2])) {
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