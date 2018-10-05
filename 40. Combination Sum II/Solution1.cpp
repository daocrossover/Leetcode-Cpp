// Description:
// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]


#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        // first sorting
        sort(candidates.begin(), candidates.end());
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
                    // avoid duplicates!
                    if (i > start && candidates[i] == candidates[i-1]) continue;
                    cur.push_back(candidates[i]);
                    backtrack(res, cur, candidates, remain - candidates[i], i + 1);
                    cur.pop_back();
                }
            }
        }
    }
};