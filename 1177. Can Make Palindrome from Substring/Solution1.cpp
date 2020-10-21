// 1177. Can Make Palindrome from Substring
// Description:
// Given a string s, we make queries on substrings of s.
// For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right], and then choose up to k of them to replace with any lowercase English letter. 
// If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.
// Return an array answer[], where answer[i] is the result of the i-th query queries[i].
// Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa", and k = 2, we can only replace two of the letters.  
// (Also, note that the initial string s is never modified by any query.)

// Example :
// Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
// Output: [true,false,false,true,true]
// Explanation:
// queries[0] : substring = "d", is palidrome.
// queries[1] : substring = "bc", is not palidrome.
// queries[2] : substring = "abcd", is not palidrome after replacing only 1 character.
// queries[3] : substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
// queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.
 
// Constraints:
// 1. 1 <= s.length, queries.length <= 10^5
// 2. 0 <= queries[i][0] <= queries[i][1] < s.length
// 3. 0 <= queries[i][2] <= s.length
// 4. s only contains lowercase English letters.

// Prefix Sum Idea - count each character
// Then get the number of character which has odd appearance in range [left, right]
// k replacement could cover half count

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(26, 0));
        vector<bool> res;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1];
            dp[i][s[i-1] - 'a']++;
        }
        for (auto q: queries) {
            int left = q[0], right = q[1], k = q[2];
            int count = 0;
            for (int j = 0; j < 26; ++j) {
                int num = dp[right+1][j] - dp[left][j];
                count += num % 2;
            }
            res.push_back(count / 2 <= k);
        }
        return res;
    }
};