// Description:
// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
// Note that every number in the answer must not have leading zeros except for the number 0 itself. 
// For example, 01 has one leading zero and is invalid, but 0 is valid.
// You may return the answer in any order.

// Example 1:
// Input: N = 3, K = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.

// Example 2:
// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

// Note:
// 1. 1 <= N <= 9
// 2. 0 <= K <= 9

// DFS Solution:

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if (N == 1) res.push_back(0);
        for (int i = 1; i <= 9; ++i) {
            dfs(N - 1, K, i, res);
        }
        return res;
    }

private:
    void dfs(int N, int K, int cur, vector<int>& res) {
        if (N == 0) {
            res.push_back(cur);
            return;
        }
        int l = cur % 10;
        if (l + K < 10) {
            dfs(N - 1, K, cur * 10 + l + K, res);
        }
        if (l - K >= 0 && K > 0) {
            dfs(N - 1, K, cur * 10 + l - K, res);
        }
    }
};