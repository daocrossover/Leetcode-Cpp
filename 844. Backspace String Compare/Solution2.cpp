// Two pointers solution:
// Iterate through the string in reverse. 
// If we see a backspace character, the next non-backspace character is skipped.
// If a character isn't skipped, it is part of the final answer.

#include<string>
using std::string;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        while (i >= 0 || j >= 0) {
            deleteChar(S, i);
            deleteChar(T, j);
            if (i >= 0 && j >= 0 && S[i] != T[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    
    void deleteChar(string s, int &i) {
        int skip = 0;
        while (i >= 0) {
            if (s[i] == '#') {
                skip++;
                i--;
            } else if (skip > 0) {
                skip--;
                i--;
            } else {
                break;
            }
        }
    }
};