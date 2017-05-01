/*
 * Handles IO & runs the algorithm
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "algorithm.h"

using namespace std;

/**
 * Retrieves string from file
 */
void readStringFromFile(const char *fileName, string &dst) {
    ifstream inFile;
    stringstream ss;
    string line;

    inFile.open(fileName);
    while (getline(inFile, line)) {
        ss << line;
    }
    inFile.close();

    dst = string(ss.str());
}

int main(int argc, const char* argv[]) {
    // Retrieve Arguments
    string s1, s2;
    readStringFromFile(argv[1], s1);
    readStringFromFile(argv[2], s2);
    const char *arg1 = s1.c_str();
    const char *arg2 = s2.c_str();

    // Run specified algorithm for result
    char* result = new char[solver->getMaxResultLength(arg1, arg2) + 1];
    solver->solve(arg1, arg2, result);

    // Print result
    cout << result << endl;

    delete result;
    return 0;
}