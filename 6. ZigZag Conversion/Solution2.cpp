// Sort by Row Solution:

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        vector<string> rows(numRows, "");
        int i = 0, n = s.length();
        while (i < n) {
            for (int j = 0; j < numRows && i < n; ++j) {
                rows[j] += s[i++]; // from top to down
            }
            for (int j = numRows - 2; j >= 1 && i < n; --j) {
                rows[j] += s[i++]; // from down to top
            }
        }
        for (string row: rows) {
            res += row;
        }
        return res;
    }
};