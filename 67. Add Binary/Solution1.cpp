// Description:
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        string s = "";
        while (i >= 0 || j >= 0 || carry == 1) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            s += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};