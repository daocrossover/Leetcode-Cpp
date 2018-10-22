// "good index": if starting at that position, we can reach the last index.
// Otherwise, that index is called a "bad index".
// The problem then reduces to whether or not index 0 is a "good index".

// Dynamic Programming: top-down
// Time complexity: O(n^2)
// For every element in the array, say i,
// we are looking at the next nums[i] elements to its right aiming to find a GOOD index.
// nums[i] can be at most n, where n is the length of array nums.
// Space complexity: O(2n) = O(n).
// First n originates from recursion.
// Second n comes from the usage of the memo table.

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
        vector<int> memo(nums.size(), 0);
        memo[memo.size() - 1] = 1;
        return canJumpFromPosition(0, nums);
    }

    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (memo[position] != 0) {
            return memo[position] == 1 ? true : false;
        }

        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = 1;
                return true;
            }
        }

        memo[position] = -1;
        return false;
    }
};