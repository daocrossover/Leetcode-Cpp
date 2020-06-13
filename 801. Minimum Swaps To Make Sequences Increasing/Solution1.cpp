// Description:
// We have two integer sequences A and B of the same non-zero length.
// We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.
// At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
// Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

// Example:
// Input: A = [1,3,5,4], B = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap A[3] and B[3].  Then the sequences are:
// A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
// which are both strictly increasing.

// Note:
// 1. A, B are arrays with the same length, and that length will be in the range [1, 1000].
// 2. A[i], B[i] are integer values in the range [0, 2000].

// Dynamic Programming Solution:
// swap[i]: minimum number of swaps for range [0, i] in increasing order and swap at position i
// keep[i]: minimum number of swaps for range [0, i] in increasing order and don't swap at position i
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<vector>
using std::vector;
using std::min;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> swap(n, n), keep(n, n);
        swap[0] = 1;
        keep[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i-1] && B[i] > B[i-1]) {
                // good case, no need to swap
                keep[i] = keep[i-1];
                // swap A[i-1] and B[i-1] && swap A[i] and B[i]
                swap[i] = swap[i-1] + 1;
            }
            
            // The second if includes the first if
            if (A[i] > B[i-1] && B[i] > A[i-1]) {
                // keep A[i] and B[i] && swap A[i-1] and B[i-1]
                keep[i] = min(keep[i], swap[i-1]);
                // swap A[i] and B[i] && keep A[i-1] and B[i-1]
                swap[i] = min(swap[i], keep[i-1] + 1);
            }
        }
        return min(keep[n-1], swap[n-1]);
    }
};