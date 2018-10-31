// Description:
// Initially on a notepad only one character 'A' is present.
// You can perform two operations on this notepad for each step:
// 1. Copy All: You can copy all the characters present
// on the notepad (partial copy is not allowed).
// 2. Paste: You can paste the characters which are copied last time.

// Given a number n. You have to get exactly n 'A' on the notepad
// by performing the minimum number of steps permitted.
// Output the minimum number of steps to get n 'A'.

// Example 1:
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.

// Note:
// The n will be in the range [1, 1000].


// Dynamic Programming Solution:
// dp[k]: minimum number of steps to get exactly k 'A' on the notepad.
// Assume the number of 'A' on the notepad is i when this Copy All operation is performed.
// we need more (k-i)/i steps
// So the total number of steps from getting i 'A' to k 'A'
// steps = 1 + (k-i)/i = k/i, one Copy All plus (k-i)/i Paste.
// Hence, dp[k] = min{dp[i] + k/i} where 1 <= i < k && k % i == 0.
// Time Complexity: O(n^2), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
		dp[1] = 0;
        for (int k = 2; k <= n; ++k) {
            for (int i = 1; i < k; ++i) {
                if (k % i != 0) continue;
                dp[k] = min(dp[k], dp[i] + k / i);
            }
        }
        return dp[n];
    }
};
