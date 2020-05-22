// Description:
// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Note: The length of the given binary array will not exceed 50,000.

// Hashmap solution: (preMap idea)
// Using a hashmap to store <count, index>
// if the count is found in the map -> the subarray between index1 and index2 contains equal number of 0 and 1.

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap;
        countMap.insert({0, -1});
        int count = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1) ? 1 : -1;
            if (countMap.count(count)) {
                maxLen = max(maxLen, i - countMap[count]);
            } else {
                countMap[count] = i;
            }
        }
        return maxLen;
    }
};