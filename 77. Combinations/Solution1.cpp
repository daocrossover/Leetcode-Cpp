// Description:
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, n, k, 1);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, int n, int k, int start) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        } else {
            for (int i = start; i <= n; ++i) {
                cur.push_back(i);
                backtrack(res, cur, n, k, i + 1);
                cur.pop_back();
            }
        }
    }
};