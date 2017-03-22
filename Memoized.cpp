#include <string>
#include "algorithm.h"

using namespace std;

class MemoizedSolver: public AlgorithmSolver {
public:
    const char *solve(const char *s1, const char *s2) const override {
        return "memoized result";
    }
};

AlgorithmSolver* solver = new MemoizedSolver();
