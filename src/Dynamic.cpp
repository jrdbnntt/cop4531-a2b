/*
 * Dynamic Algorithm from book:
 * DYNAMIC-LCS(X,Y)
 *  m = X.length
 *  n = Y.length
 *  let b[1..m, 1..n] and c[0..m, 0..n] be new tables
 *  for i = 1 to m
 *      c[i,0] = 0
 *  for j = 1 to m
 *      c[0,j] = 0
 *  for i = 1 to m
 *      for j = 1 to n
 *          if xi == yj
 *              c[i,j] = c[i-1,j-1] + 1
 *              b[1,j] = NE Direction
 *          else if c[i-1,j] >= c[i,j-1]
 *              c[i,j] = c[i-1,j]
 *              b[i,j] = N Direction
 *          else
 *              c[i,j] = c[i,j-1]
 *              b[i,j] = W Direction
 * return CONSTRUCT-LCS(X,Y,c,b)
 *
 * CONSTRUCT-LCS(X,Y,c,b)
 *  result = ""
 *  i = X.length - 1
 *  j = Y.length - 1
 *  while (i >= 1 && j >= 1 && c[i][j] > 0)
 *      direction = b[i][j]
 *      if direction == NE Direction
 *          result += X[i]
 *          --j
 *          --i
 *      else if direction == N Direction
 *          --i
 *      else // west
 *          --j
 *  return result
 *
 * DynamicSolver.solve(X, Y) is the implementation of the above algorithms
 */


#include <cstring>
#include "algorithm.h"

using namespace std;

enum TABLE_DIRECTION {
    N, NW, W
};


class DynamicSolver : public AlgorithmSolver {
public:
    const char *solve(const char *s1, const char *s2, char *result) const override {

        // Get size
        int m = static_cast<int>(strlen(s1))+1;
        int n = static_cast<int>(strlen(s2))+1;

        // Allocate count & direction tables (default initialization value is desired)
        int** c = new int*[m];
        TABLE_DIRECTION** b = new TABLE_DIRECTION*[m];
        for (int i = 0; i < m; ++i) {
            b[i] = new TABLE_DIRECTION[n];
            c[i] = new int[n];

        }
        // Init top + left rows to 0
        for (int i = 0; i < m; ++i) {
            c[i][0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            c[0][j] = 0;
        }

        // Populate b and c via Dynamic Programming
        for (int i = 1; i < m; ++i) {
            for (int j = 1 ; j < n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    // Match, go diagonal
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = NW;
                } else if (c[i-1][j] >= c[i][j-1]) {
                    // North has >= value, go there
                    c[i][j] = c[i-1][j];
                    b[i][j] = N;
                } else {
                    // West has greater value, go there
                    c[i][j] = c[i][j-1];
                    b[i][j] = W;
                }
            }
        }

        // Copy result string of LCS to c-string by following NE corner back and storing each char right to left
        {
            int i = m - 1, j = n - 1;
            result[c[i][j]] = '\0';
            while (i >= 1 && j >= 1 && c[i][j] > 0) {
                switch (b[i][j]) {
                    case NW: // Actual match, record char and move
                        result[c[i][j] - 1] = s1[i - 1];
                        --i;
                        --j;
                        break;
                    case N: // No match, just move
                        --i;
                        break;
                    case W: // No match, just move
                        --j;
                        break;
                }
            }
        }

        // Deallocate tables
        for (int i = 0; i < m; ++i) {
            delete c[i];
            delete b[i];
        }
        delete c;
        delete b;

    }
};

AlgorithmSolver* solver = new DynamicSolver();
