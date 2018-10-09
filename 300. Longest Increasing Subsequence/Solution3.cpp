// DP + Binary search
// Time Complexity: O(nlogn), Space Complexity: O(n)

// tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
// For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:
// len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
// len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
// len = 3   :      [4, 5, 6]            => tails[2] = 6

// We can easily prove that tails is a increasing array.
// Therefore it is possible to do a binary search in tails array to find the one needs update.

// Each time we only do one of the two:
// (1) if x is larger than all tails, append it, increase the size by 1
// (2) if tails[i-1] < x <= tails[i], update tails[i]

#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails(n);
        int size = 0;
        for (int i = 0; i < n; ++i) {
            int low = 0, high = size;
            while (low != high) {
                int mid = (low + high) / 2;
                if (tails[mid] < nums[i])
                    low = mid + 1;
                else
                    high = mid;
            }
            tails[low] = nums[i];
            if (low == size) size++;
        }
        return size;
    }
};