/*
 * Memoized algorithm, starting from the bottom-right table corner
 * MEMOIZED-LCS(X,Y)
 *  m = X.length
 *  n = Y.length
 *  let b[1..m, 1..n] and c[0..m, 0..n] be new tables
 *  for i = 1 to m
 *      c[i,0] = 0
 *  for j = 1 to m
 *      c[0,j] = 0
 *   for i = 1 to m
 *      for j = 1 to m
 *          c[i,j] = -1
 *  MEMOIZED-LCS-AUX(X,Y,c,m,n)
 *  return CONSTRUCT-LCS(X,Y,c,b)
 *
 * MEMOIZED-LCS-AUX(X,Y,b,c,i,j)
 *  if c[i,j] >= 0
 *      // Already calculated (the memoization)
 *  else if X[i] == Y[j]
 *      c[i,j] = MEMOIZED-LCS-AUX(X,Y,b,c,i-1,j-1) + 1
 *      b[1,j] = NE Direction
 *  else if MEMOIZED-LCS-AUX(X,Y,b,c,i-1,j) >= MEMOIZED-LCS-AUX(X,Y,b,c,i,j-1)
 *      c[i,j] = MEMOIZED-LCS-AUX(X,Y,b,c,i-1,j)
 *      b[i,j] = N Direction
 *  else
 *      c[i,j] = MEMOIZED-LCS-AUX(X,Y,b,c,i,j-1)
 *      b[i,j] = W Direction
 *  return c[i,j]
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
 *  MemoizedSolver.solve(X, Y) is the implementation of the above algorithms
 */


#include <cstring>
#include "algorithm.h"

using namespace std;

enum TABLE_DIRECTION {
    N, NW, W
};


class MemoizedSolver: public AlgorithmSolver {
private:
    const int solveAux(const char *s1, const char *s2, int** c, TABLE_DIRECTION** b, int i, int j) const {
        if (c[i][j] >= 0) {
            return c[i][j];
        }

        if (s1[i-1] == s2[j-1]) {
            c[i][j] = solveAux(s1,s2,c,b,i-1,j-1) + 1;
            b[i][j] = NW;
        } else if (solveAux(s1,s2,c,b,i-1,j) >= solveAux(s1,s2,c,b,i,j-1)) {
            c[i][j] = solveAux(s1,s2,c,b,i-1,j);
            b[i][j] = N;
        } else {
            c[i][j] = solveAux(s1,s2,c,b,i,j-1);
            b[i][j] = W;
        }
        return c[i][j];
    }


public:
    const char *solve(const char *s1, const char *s2, char *result) const override {
        // Get size
        int m = static_cast<int>(strlen(s1))+1;
        int n = static_cast<int>(strlen(s2))+1;

        // Allocate count & direction tables (default initialization value is desired)
        int** c = new int*[m];
        TABLE_DIRECTION** b = new TABLE_DIRECTION*[m];
        for (int i = 0; i < m; ++i) {
            c[i] = new int[n];
            b[i] = new TABLE_DIRECTION[n];
        }
        // Init top + left rows to 0
        for (int i = 0; i < m; ++i) {
            c[i][0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            c[0][j] = 0;
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                c[i][j] = -1;
            }
        }

        // Populate b and c via Memoization
        solveAux(s1, s2, c, b, m-1, n-1);

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

AlgorithmSolver* solver = new MemoizedSolver();
