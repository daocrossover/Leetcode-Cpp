// Description:
// Given a non-negative integer num represented as a string,
// remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// using stack:

#include<string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int rest = num.length() - k;
        string res = "";
        for (int i = 0; i < num.length(); ++i) {
            while (res.size() > 0 && res.back() > num[i] && k > 0) {
                // if the previous character in num is larger than the current one
                // then removing it will get a smaller number
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.resize(rest);
        int s = 0;
        // erase zero in front of the string
        while (s < (int)res.size()-1 && res[s] == '0') s++;
        res.erase(0, s);
        return res == "" ? "0" : res;
    }
};