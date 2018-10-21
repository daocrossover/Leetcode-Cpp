// Description:
// Given two non-negative integers num1 and num2 represented as strings,
// return the product of num1 and num2, also represented as a string.

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Note:
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


// num1[i] * num2[j] will be placed at indices [i + j, i + j + 1]

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> pos(m + n, 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int digit = i + j + 1;
                int carry = i + j;
                int sum = product + pos[digit];
                pos[digit] = sum % 10;
                pos[carry] += sum / 10;
            }
        }
        string res = "";
        for (int i = 0; i < pos.size(); ++i) {
            if (!(res == "" && pos[i] == 0)) {
                res += (pos[i] + '0');
            }
        }
        return res == "" ? "0" : res;
    }
};