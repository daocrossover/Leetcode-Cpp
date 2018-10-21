// Put each number in its right place.
// For any array whose length is l, the first missing positive must be in range [1,...,l+1]
// When we find 5, then swap it with nums[4]. Put nums[i] to nums[nums[i] - 1].
// At last, the first place where its number is not right, return the place + 1.
// Time Complexity: O(n), Space Complexity: O(1)
 
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // using while
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};