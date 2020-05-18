// Description:
// Given an unsorted array of integers,
// find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.


// Using set
// Time Complexity: O(n), Space Complexity: O(n)

#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            st.insert(nums[i]);
        }
        
        int maxLen = 0;
        for (int num: st) {
            if (st.find(num-1) == st.end()) {
                int currentNum = num;
                int currentLen = 1;
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum += 1;
                    currentLen += 1;
                }
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};