// 592. Fraction Addition and Subtraction
// Description:
// Given a string expression representing an expression of fraction addition and subtraction, 
// return the calculation result in string format.

// The final result should be an irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of a fraction that has a denominator 1. 
// So in this case, 2 should be converted to 2/1.

// Example 1:
// Input: expression = "-1/2+1/2"
// Output: "0/1"

// Example 2:
// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

// Example 3:
// Input: expression = "1/3-1/2"
// Output: "-1/6"

// Example 4:
// Input: expression = "5/3+1/3"
// Output: "2/1"

// Constraints:
// 1. The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// 2. Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// 3. The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. 
// If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// 4. The number of given fractions will be in the range [1, 10].
// 5. The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

#include <sstream>
#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    int find_gcd(int a, int b) {
        // find the gcd iteratively
        int r;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    
    int find_gcd1(int a, int b) {
        // find the gcd recursively
        if (a == 0 || b == 0) {
            return a + b; // base case
        }
        return find_gcd1(b, a % b);
    }

    void add(int &a, int &b, int c, int d) {
        // calculate sum of a/b + c/d = (a * d + c * b) / b * d
        // then divide both the numerator and denominator by their gcd
        int num = a * d + c * b;
        int den = b * d;
        int gcd = find_gcd(abs(num), abs(den));
        a = num / gcd;
        b = den / gcd;
    }
    
    string fractionAddition(string expression) {
        std::stringstream ss(expression);
        char op;
        int a, b, c, d;
        ss >> a; 
        ss >> op; 
        ss >> b;
        while (ss >> c) {
            ss >> op;
            ss >> d;
            add(a, b, c, d);
        }
        return to_string(a) + "/" + to_string(b);
    }
};