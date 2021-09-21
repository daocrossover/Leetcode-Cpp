// 167. Two Sum II - Input array is sorted
// Description:
// Given an array of integers numbers that is already sorted in non-decreasing order, 
// find two numbers such that they add up to a specific target number.
// Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, 
// where 1 <= answer[0] < answer[1] <= numbers.length.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Example 1:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

// Example 2:
// Input: numbers = [2,3,4], target = 6
// Output: [1,3]

// Example 3:
// Input: numbers = [-1,0], target = -1
// Output: [1,2]

// Constraints:
// 1. 2 <= numbers.length <= 3 * 10^4
// 2. -1000 <= numbers[i] <= 1000
// 3. numbers is sorted in non-decreasing order.
// 4. -1000 <= target <= 1000
// 5. The tests are generated such that there is exactly one solution.

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int>{i + 1, j + 1};
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return vector<int>{-1, -1};
    }
};