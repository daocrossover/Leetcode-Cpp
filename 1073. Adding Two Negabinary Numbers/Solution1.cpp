// 1073. Adding Two Negabinary Numbers
// Description:
// Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
// Each number is given in array format: as an array of 0s and 1s, from most significant bit to least significant bit. 
// For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.
// A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

// Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

// Example 1:
// Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
// Output: [1,0,0,0,0]
// Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.

// Example 2:
// Input: arr1 = [0], arr2 = [0]
// Output: [0]

// Example 3:
// Input: arr1 = [0], arr2 = [1]
// Output: [1]

// Constraints:
// 1. 1 <= arr1.length, arr2.length <= 1000
// 2. arr1[i] and arr2[i] are 0 or 1
// 3. arr1 and arr2 have no leading zeros

// Carry:          1 −1  0 −1  1 −1  0  0  0
// First addend:         1  0  1  0  1  0  1
// Second addend:        1  1  1  0  1  0  0 +
//                --------------------------
// Number:         1 −1  2  0  3 −1  2  0  1
// Bit (result):   1  1  0  0  1  1  0  0  1
// Carry:          0  1 −1  0 −1  1 −1  0  0

// carry could be -1, 0, 1
// sum = -1 = 1 + 1 * (-2)   -> bit = 1, carry = 1
// sum = 0                   -> bit = 0, carry = 0
// sum = 1                   -> bit = 1, carry = 0
// sum = 2 = 0 + (-1) * (-2) -> bit = 0, carry = -1
// sum = 3 = 1 + (-1) * (-2) -> bit = 1, carry = -1

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];
            res.push_back(carry & 1); // reverse the vector in the end
            carry = -(carry >> 1);
        }
        // remove the leading zeros
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};