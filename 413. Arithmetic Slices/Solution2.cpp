// Constant Space Dynamic Programming Solution:
// observe that we only require the element dp[i-1] to determine the value to be entered at dp[i].
// Thus, instead of making use of a 1-D array to store the required data,
// we can simply keep a track of just the last element.

#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int res = 0;
        int dp = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp = dp + 1;
                res += dp;
            } else {
                dp = 0;
            }
        }
        return res;
    }
};
