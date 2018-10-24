// Description:
// Given an absolute path for a file (Unix-style), simplify it. 

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// path = "/a/../../b/../c//.//", => "/c"
// path = "/a//b////c/d//././/..", => "/a/b/c"

// In a UNIX-style file system, a period ('.') refers to the current directory,
// so it can be ignored in a simplified path.
// Additionally, a double period ("..") moves up a directory,
// so it cancels out whatever the last directory was.
// For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".


// Stack Solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        int i = 0, j = 0;
        while (i < path.length()) {
            if (path[i] == '/') {
                // escape duplicate '/'
                j = i;
                while (j < path.length() && path[j] == '/') {
                    j++;
                }
            } else {
                // get the string between '/' and '/'
                j = i;
                while (j < path.length() && path[j] != '/') {
                    j++;
                }
                string name = path.substr(i, j - i);
                if (name == "..") {
                    if (!dir.empty()) {
                        dir.pop_back();
                    }
                } else if (name != ".") {
                    dir.push_back(name);
                }
            }
            i = j;
        }
        
        string res = "";
        for (int i = 0; i < dir.size(); ++i) {
            res += ("/" + dir[i]);
        }
        return res.empty() ? "/" : res;
    }
};