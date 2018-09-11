// Description:
// Given a sorted integer array without duplicates, return the summary of its ranges.

// Example 1:
// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

// Example 2:
// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int i = 0, start = 0;
        while (i < nums.size()) {
            int j = i + 1;
            if (j < nums.size() && nums[i] + 1 == nums[j]) {
                ++i;
                ++j;
            } else {
                if (i == start) {
                    res.push_back(to_string(nums[start]));
                } else {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                }
                ++i;
                start = i;
            }
        }
        return res;
    }
};