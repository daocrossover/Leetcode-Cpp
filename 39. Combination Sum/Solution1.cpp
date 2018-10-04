// Description:
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]


//Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, cur, candidates, target, 0);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int remain, int start) {
        if (remain < 0) {
            return;
        } else if (remain == 0) {
            res.push_back(cur);
            return;
        } else {
            for (int i = start; i < candidates.size(); ++i) {
                if (candidates[i] <= remain) {
                    cur.push_back(candidates[i]);
                    backtrack(res, cur, candidates, remain-candidates[i], i);
                    cur.pop_back();
                }
            }
        }
    }
};