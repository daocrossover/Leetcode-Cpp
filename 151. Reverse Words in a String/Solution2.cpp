// Using stringstream:

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res = "", word;
        while (ss >> word) {
            if (word != "") {
                res = word + " " + res;
            }
        }
        if (res != "") {
            res.pop_back();
        }
        return res;
    }
};