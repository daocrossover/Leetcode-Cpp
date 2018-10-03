// Description:
// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
// Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
// For example, there won't be input like 3a or 2[4].

// Examples:
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".


// Two Stacks Solution:

#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> numStack;
        stack<string> strStack;
        string num = "";
        string str = "";
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                // get num and push it to the numStack
                while (isdigit(s[i])) {
                    num += s[i++];
                }
                numStack.push(num);
                num = "";
            } else if (isalpha(s[i])) {
                // str stores the current decoded string
                str += s[i++];
            } else if (s[i] == '[') {
                // '[' means to decode a new string in []
                // push the already decoded string into strStack
                strStack.push(str);
                str = "";
                i++;
            } else if (s[i] == ']') {
                // use num(numStack.top()) to repeat current str
                // and add it to the end of the already decoded string
                int n = stoi(numStack.top());
                numStack.pop();
                string tmp = strStack.top();
                strStack.pop();
                for (int j = 0; j < n; ++j) {
                    tmp += str;
                }
                // str stores the current decoded string
                str = tmp;
                i++;
            }
        }
        return str;
    }
};