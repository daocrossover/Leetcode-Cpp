// using stack:

#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0;  // i and j mark end and start of sliding window of segment
        int j = 0;
        bool is_file;  // Flag set when segment contains '.'
        int depth;  // Number of tabs preceeding relative path
        stack<int> sums;  // A stack of prefix sums of path segment lengths
        unsigned long max_len = 0;  // Current max length
        
        while (i < input.size()) {
            // Reset file flag and depth
            is_file = false;
            depth = 0;
            
            // Count tabs
            while (input[i] == '\t') {
                depth++;
                i++;
            }
            
            // If current stack size greater than depth that means we need
            // to backtrack accordingly
            while (sums.size() > depth) {
                sums.pop();
            }
            
            // Set start of window
            j = i;
            
            // Set end of window and possibly file flag
            while ((i < input.size()) && !(input[i] == '\n')) {
                if (input[i] == '.')
                    is_file = true;
                i++;
            }
            
            // Push new path length onto top of stack
            if (sums.size() == 0)
                sums.push(i - j);
            else
                sums.push(i - j + sums.top());
            
            // Update max_len if file
            if (is_file)
                max_len = max(max_len, sums.top() + sums.size() - 1);
                
            i++;
        }
        
        return max_len;
    }
};