// Using Sorting and two pointers without the median
// Time Complexity: O(nlogn) (average)

#include <vector>
using std::vector;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int moves = 0;
        while (i < j) {
            moves += nums[j] - nums[i];
            i++;
            j--;
        }
        return moves;
    }
};