// Divide and Conquer(recursion) Solution:

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.length(), k);
    }

    int helper(string str, int start, int end, int k) {
        //substring length shorter than k.
        if (end - start < k) return 0;
        vector<int> count(26);
        for (int i = start; i < end; ++i) {
            int idx = str[i] - 'a';
            count[idx]++;
        }
        for (int i = 0; i < 26; ++i) {
            //count[i]=0 => i+'a' does not exist in the string, skip it.
            if (count[i] < k && count[i] > 0) {
                for (int j = start; j < end; ++j) {
                    if (str[j] == i + 'a') {
                        int left = helper(str, start, j, k);
                        int right = helper(str, j+1, end, k);
                        return max(left, right);
                    }
                }
            }
        }
        return end - start;
    }
};