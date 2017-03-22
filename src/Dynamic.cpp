#include <string>
#include "algorithm.h"

using namespace std;

class DynamicSolver : public AlgorithmSolver {
public:
    const char *solve(const char *s1, const char *s2) const override {
        return "dynamic result";
    }
};

AlgorithmSolver* solver = new DynamicSolver();
