// Description:
// Given an array nums of n integers where n > 1, 
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:
// Input:  [1,2,3,4]
// Output: [24,12,8,6]

// Note: Please solve it without division and in O(n).
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

// my own trash solution:

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, product1 = 1, count = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                product = 0;
                count++;
            } else {
                product1 *= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && count == 1) {
                res.push_back(product1);
            } else if (nums[i] == 0 && count > 1) {
                res.push_back(0);
            } else {
                if (product == 0) {
                    res.push_back(product / nums[i]);
                } else {
                    res.push_back(product1 / nums[i]);
                }
            }
        }
        return res;
    }
};