/**
 * Common header file to prevent duplicate code and easier testing
 */


#ifndef ALGORITHM_H
#define ALGORITHM_H

/**
 * Abstract solver, to be extended by each of the two solutions
 */
class AlgorithmSolver {
public:

    int getMaxResultLength(const char *s1, const char *s2) const {
        int len1 = static_cast<int>(strlen(s1));
        int len2 = static_cast<int>(strlen(s2));
        return len1 >= len2? len1 : len2;
    }

    /**
     * Preforms the algorithm and returns result
     *
     * @param s1 string that contain characters in A­Z
     * @param s2 string that contain characters in A­Z
     * @return optimum longest common subsequence of s1 and s2
     */
    virtual const char *solve(const char *s1, const char *s2, char *result) const = 0;

};

extern AlgorithmSolver* solver; // Solver used by main (set in each compiled solution)

#endif
