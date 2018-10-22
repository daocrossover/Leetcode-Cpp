// "good index": if starting at that position, we can reach the last index.
// Otherwise, that index is called a "bad index".
// The problem then reduces to whether or not index 0 is a "good index".

// Dynamic Programming: bottom-up
// Time complexity: O(n^2)
// For every element in the array, say i,
// we are looking at the next nums[i] elements to its right aiming to find a GOOD index.
// nums[i] can be at most n, where n is the length of array nums.
// Space complexity: O(n). This comes from the usage of the memo table.


#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> memo;
    // GOOD: 1
    // UNKNOWN: 0
    // BAD: -1
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 0);
        memo[memo.size() - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            int furthestJump = min(i + nums[i], n - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == 1) {
                    memo[i] = 1;
                    break;
                }
            }
        }

        return memo[0] == 1;
    }
};