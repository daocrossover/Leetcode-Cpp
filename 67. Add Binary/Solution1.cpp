// Description:
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            int add1 = i >= 0 ? a[i] - '0' : 0;
            int add2 = j >= 0 ? b[j] - '0' : 0;
            int sum = add1 + add2 + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            i--;
            j--;
        }
        if (carry) res = "1" + res;
        return res;
    }
};