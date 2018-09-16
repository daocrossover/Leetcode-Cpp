// Description:
// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:
// Input: [1,2,3,4,5]
// Output: true

// Example 2:
// Input: [5,4,3,2,1]
// Output: false

#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, secondMin = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= min) min = nums[i];
            else if(nums[i] < secondMin) secondMin = nums[i];
            else if(nums[i] > secondMin) return true;
        }
        return false;
    }
};