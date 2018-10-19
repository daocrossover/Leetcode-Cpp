// Recursive Solution:

#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string preStr = countAndSay(n-1);
        string res = "";
        int preCharCount = 1;
        char preChar = preStr[0];
        for (int i = 1; i < preStr.length(); ++i) {
            char curChar = preStr[i];
            if (preChar == curChar) {
                preCharCount++;
            } else {
                res += to_string(preCharCount) + preChar;
                preChar = curChar;
                preCharCount = 1;
            }
        }
        res += to_string(preCharCount) + preChar;
        return res;
    }
};