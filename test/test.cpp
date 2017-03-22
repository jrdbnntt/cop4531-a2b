/*
 * Common test utilities
 */
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <exception>
#include <string>
#include <iostream>
#include "../src/algorithm.h"

using namespace std;

struct TestCase {
    const char* s1;
    const char* s2;
    const char* expectedResult;

    TestCase(const char* s1, const char* s2, const char* expectedResult) {
        this->s1 = s1;
        this->s2 = s2;
        this->expectedResult = expectedResult;
    }

    bool check(const char* result) const {
        return strcmp(expectedResult, result) == 0;
    }
    ostream& printSizeSummary(ostream& out) const {
        out << "[" << strlen(s1) << ":" << to_string(strlen(s2)) << "=" << strlen(expectedResult) << "]";
        return out;
    }

    bool test(AlgorithmSolver *solver) const;

};


class TestException : public exception {
public:
    TestException(const TestCase* testCase, const char* message, const char* result) {
        this->message = "[ \"" + string(testCase->s1) + "\", \"" + string(testCase->s2) + "\" ] :: " + string(message) + " :: ";
        this->message += "Expected \"" + string(testCase->expectedResult);
        this->message += "\", Got \"" + string(result) + "\"";
    }

    virtual const char* what() const throw() {
        return message.c_str();
    }

private:
    string message;
};


bool TestCase::test(AlgorithmSolver *solver) const {
    char* result = new char[solver->getMaxResultLength(s1, s2) + 1];
    solver->solve(s1, s2, result);
    if (!check(result)) {
        throw TestException(this, "FAILED", result);
    };
    delete result;
}


/*
 * Defined test cases
 */
const vector<TestCase> simple_cases = vector<TestCase>({
        TestCase("", "", ""),
        TestCase("A", "A", "A"),
        TestCase("A", "B", ""),
        TestCase("AB", "B", "B"),
        TestCase("AB", "AB", "AB"),
        TestCase("ABC", "AB", "AB"),
        TestCase("ABC", "C", "C"),
        TestCase("ABC", "AC", "AC"),
        TestCase("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA", "GTCGTTCGGAATGCCGTTGCTCTGTAAA", "GTCGTCGGAAGCCGGCCGAA")
});


/*
 * Generator utilities
 */


/**
 * Construct random valid string [A-Z] argument with given length
 * @param len
 * @return
 */
const char* randStringArgument(int len) {
    char* str = new char[len+1];
    str[len-1] = '\0';
    srand(time(NULL)); // init random seed

    for(int i = 0; i < len; ++i) {
        str[i] = rand() % ('Z' - 'A' + 1) + 'A';
    }
    return str;
}

