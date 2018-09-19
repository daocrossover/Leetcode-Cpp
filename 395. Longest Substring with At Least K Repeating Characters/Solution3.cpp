// Sliding Window Solution:

#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> counts(26);
        int h, i, j, idx, maxLen = 0, unique, noLessThanK;
        for (h = 1; h <= 26; h++) {
            i = 0; 
            j = 0;
            unique = 0;
            noLessThanK = 0;
            while (j < s.length()) {
                if (unique <= h) {
                    idx = s[j] - 'a';
                    if (counts[idx] == 0)
                        unique++;
                    counts[idx]++;
                    if (counts[idx] == k)
                        noLessThanK++;
                    j++;
                }
                else {
                    idx = s[i] - 'a';
                    if (counts[idx] == k)
                        noLessThanK--;
                    counts[idx]--;
                    if (counts[idx] == 0)
                        unique--;
                    i++;
                }
                if (unique == h && unique == noLessThanK)
                    maxLen = max(j - i, maxLen);
            }
        }
        return maxLen;
    }
};