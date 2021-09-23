// 556. Next Greater Element III
// Description:
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. 
// If no such positive integer exists, return -1.

// Note that the returned integer should fit in 32-bit integer, 
// if there is a valid answer but it does not fit in 32-bit integer, return -1.

// Example 1:
// Input: n = 12
// Output: 21

// Example 2:
// Input: n = 21
// Output: -1

// Constraints:
// 1 <= n <= 2^31 - 1

// Actually the same as 31. Next Permutation
// But need to check the overflow

#include <string>
using std::string;
using std::swap;

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = std::to_string(n);
        int i = num.size() - 2;
        while (i >= 0 && num[i+1] <= num[i]) {
            i--;
        }
        if (i < 0) {
            // decreasing number
            return -1;
        }
        int j = num.size() - 1;
        while (j >= 0 && num[j] <= num[i]) {
            j--;
        }
        swap(num[i], num[j]);
        reverse(num, i + 1);
        long next = stol(num); // using stol instead of stoi
        return next > INT_MAX ? -1 : next; // check the overflow
    }
    
    void reverse(string& num, int start) {
        int i = start, j = num.size() - 1;
        while (i < j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }
};