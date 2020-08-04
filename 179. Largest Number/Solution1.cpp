// Description:
// Given a list of non negative integers, arrange them such that they form the largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.

// Sorting via Custom Comparator

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::to_string;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n: nums) {
            strs.push_back(to_string(n));
        }
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 > s2 + s1;});
        if (strs[0] == "0") {
            return "0";
        }
        string res;
        for (string s: strs) {
            res += s;
        }
        return res;
    }
};