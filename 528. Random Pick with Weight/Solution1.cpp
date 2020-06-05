// Description:
// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

// Note:
// 1. 1 <= w.length <= 10000
// 2. 1 <= w[i] <= 10^5
// 3. pickIndex will be called at most 10000 times.

// Example 1:
// Input: 
// ["Solution","pickIndex"]
// [[[1]],[]]
// Output: [null,0]

// Example 2:
// Input: 
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// Output: [null,0,1,1,1,0]
// Explanation of Input Syntax:
// The input is two lists: the subroutines called and their arguments.
// Solution's constructor has one argument, the array w. pickIndex has no arguments.
// Arguments are always wrapped with a list, even if there aren't any.

// Binary Search Solution:
// w: [1, 3, 2], sum array: [1, 4, 6]
// x = rand() % 6 -> x is in [0, 5]
// x = 0 -> 1
// x = 1, 2, 3 -> 4
// x = 4, 5 -> 6
// Therefore, find the first number which is larger than x in the sum array

#include<vector>
using std::vector;

class Solution {
private:
    vector<int> sum;

public:
    Solution(vector<int>& w) {
        int s = 0;
        for (int weight: w) {
            s += weight;
            sum.push_back(s);
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back();
        int left = 0, right = sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */