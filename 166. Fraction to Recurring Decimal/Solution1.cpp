// 166. Fraction to Recurring Decimal
// Description:
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.
// If multiple answers are possible, return any of them.
// It is guaranteed that the length of the answer string is less than 10^4 for all the given inputs.

// Example 1:
// Input: numerator = 1, denominator = 2
// Output: "0.5"

// Example 2:
// Input: numerator = 2, denominator = 1
// Output: "2"

// Example 3:
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"

// Example 4:
// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Example 5:
// Input: numerator = 1, denominator = 5
// Output: "0.2"

// Constraints:
// 1. -231 <= numerator, denominator <= 231 - 1
// 2. denominator != 0

// No quick method, but pay attention to corner cases

#include <string>
#include <unordered_map>
using std::string;
using std::to_string;
using std::unordered_map;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // corner case 1: numerator = 0
        if (numerator == 0) {
            return "0";
        }
        string res;
        // corner case 2: "+" or "-"
        if (numerator < 0 ^ denominator < 0) {
            // XOR
            res.append("-");
        }
        // corner case 3: integer overflow when * 10
        long num = (long)abs(numerator); // remove sign of operands
        long den = (long)abs(denominator);
        // integral part
        res.append(to_string(num / den));
        num %= den;
        if (num == 0) {
            return res;
        }
        // fractional part
        res.append(".");
        unordered_map<int, int> location; // use HashMap to store a remainder and its associated index 
        location[num] = res.length();
        while (num != 0) {
            num *= 10;
            res.append(to_string(num / den));
            num %= den;
            if (location.find(num) != location.end()) {
                int index = location[num];
                res.insert(index, "(");
                res.append(")");
                break;
            } else {
                location[num] = res.length();
            }
        }
        return res;
    }
};