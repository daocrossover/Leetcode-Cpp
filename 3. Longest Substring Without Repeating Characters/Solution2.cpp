// Hashset + two pointers
// using hashset to store the characters in current window [i, j) (j == i initially)
// Slide the index j to the right. If it is not in the hashset, slide j further.
// Doing so until s[j] is already in the hashset.
// At this point, find the maximum size of substrings without duplicate characters start with index i.

// Time Complexity: O(2n) = O(n). In the worst case each character will be visited twice by i and j.
// Space Complexity: O(min(m, n)).

#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0;
        int res = 0;
        while (i < s.length() && j < s.length()) {
            if (st.count(s[j]) == 0) {
                // slide j further
                st.insert(s[j++]);
                // find the maximum substrings without duplicate characters
                if (j - i > res)
                    res = j - i;
            } else {
                // forward i until s[j] is not in the hashset
                st.erase(s[i++]);
            }
        }
        return res;
    }
};