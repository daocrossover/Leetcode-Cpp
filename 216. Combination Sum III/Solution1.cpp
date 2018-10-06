// Description:
// Find all possible combinations of k numbers that add up to a number n,
// given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, k, n, 1);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, int k, int n, int start) {
        if (k == 0 && n == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (i <= n) {
                cur.push_back(i);
                backtrack(res, cur, k-1, n-i, i+1);
                cur.pop_back();
            }
        }
    }
};