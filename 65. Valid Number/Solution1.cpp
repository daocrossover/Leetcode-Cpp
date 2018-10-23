// Description:
// Validate if a given string can be interpreted as a decimal number.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

// Note: It is intended for the problem statement to be ambiguous.
// You should gather all requirements up front before implementing one.
// However, here is a list of characters that can be in a valid decimal number:

// Numbers 0-9
// Exponent - "e"
// Positive/negative sign - "+"/"-"
// Decimal point - "."
// Of course, the context of these characters also matters in the input.

#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if (n == 0) return false;
        int i = 0;
        // ignore whitespace before
        while (s[i] == ' ') i++;
        if (s[i] == '+'|| s[i] == '-') i++;
        int point_count = 0, num_count = 0;
        // if 2 '+' or '-', num_count = 0, return false
        while (isdigit(s[i]) || s[i] == '.')  {
            s[i++] == '.' ? point_count++ : num_count++;
        }
        // no more than one point and at least one num
        if (point_count > 1 || num_count < 1) return false;
        if (s[i] == 'e') {
            i++;
            if (s[i] == '+'|| s[i] == '-') i++;
            int num_count = 0;
            while (isdigit(s[i]))  {
                i++;
                num_count++;
            }
            // at least one num
            if (num_count < 1) return false;
            // if exist dot behind the 'e', i will less than n, return false in the end
        }
        while (s[i] == ' ') i++;
        return i == n;
    }
};