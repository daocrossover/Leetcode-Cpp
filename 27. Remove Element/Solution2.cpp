// Two Pointer Solution - when elements to remove are rare:
// When encounter nums[i] = val, swap the current element out with the last element and
// dispose the last one. This essentially reduces the array's size by 1.

// Time Complexity: O(n), both i and n traverse at most nn steps.
// In this approach, the number of assignment operation is equal to
// the number of elements to remove. So it is more efficient if elements to remove are rare.
// Space Complexity: O(1).

#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};