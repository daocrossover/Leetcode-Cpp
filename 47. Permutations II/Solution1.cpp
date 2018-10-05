// Description:
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        // use an extra boolean vector to indicate whether the value is added to vector.
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(res, cur, nums, visited);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, vector<bool>& visited) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                // when a number has the same value with its previous,
                // we can use this number only if his previous is used
                if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1]))
                    continue;
                cur.push_back(nums[i]);
                visited[i] = true;
                backtrack(res, cur, nums, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};