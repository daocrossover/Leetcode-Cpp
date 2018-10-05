// Description:
// Given a collection of integers that might contain duplicates, nums,
// return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]



// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        // first sorting
        sort(nums.begin(), nums.end());
        backtrack(res, cur, nums, 0);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            // avoid duplicates!
            if (i > start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            backtrack(res, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};