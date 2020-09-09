// Shift and Count Solution:
// come up all possible overlapping zones
// Note: shifting one matrix to a direction is equivalent to shifting the other matrix to the opposite direction, 
// in the sense that we would have the same overlapping zone at the end.

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxOverlaps = 0;
        for (int yShift = 0; yShift < A.size(); ++yShift) {
            for (int xShift = 0; xShift < A.size(); ++xShift) {
                // move one of the matrice up and left and vice versa.
                // (equivalent to move the other matrix down and right)
                maxOverlaps = max(maxOverlaps, shiftAndCount(xShift, yShift, A, B));
                maxOverlaps = max(maxOverlaps, shiftAndCount(xShift, yShift, B, A));
            }
        }
        return maxOverlaps;
    }
    
private:
    int shiftAndCount(int xShift, int yShift, vector<vector<int>> A, vector<vector<int>> B) {
        int count = 0;
        int bRow = 0, bCol = 0;
        // count the cells of ones in the overlapping zone.
        for (int aRow = yShift; aRow < A.size(); ++aRow) {
            bCol = 0;
            for (int aCol = xShift; aCol < A.size(); ++aCol) {
                if (A[aRow][aCol] == 1 && A[aRow][aCol] == B[bRow][bCol]) {
                    count++;
                }
                bCol++;
            }
            bRow++;
        }
        return count;
    }
};