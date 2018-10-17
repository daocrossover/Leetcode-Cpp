// Description:
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Visiting by the row
// the cycle length should be 2(numRows-1)
// The first row index: k * cycleLen
// The numRows - 1 row index: k * cycleLen + numRows - 1
// In inner row i index: k * cycleLen + i and (k+1) * cycleLen - i

#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        int n = s.size();
        int cycleLen = 2 * (numRows - 1);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += cycleLen) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    res += s[j + cycleLen - i];
            }
        }
        return res;
    }
};