// Description:
// Given a collection of distinct integers, return all possible permutations.

// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size());
        backtrack(res, cur, nums, visited);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, vector<bool>& visited) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (visited[i] == true) continue;
                cur.push_back(nums[i]);
                visited[i] = true;
                backtrack(res, cur, nums, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};