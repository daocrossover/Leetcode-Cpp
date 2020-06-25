// Set solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return -1;
    }
};