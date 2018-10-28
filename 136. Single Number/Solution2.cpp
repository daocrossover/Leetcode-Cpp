// Using set
// if the element does not exist in the set, insert
// else delete the element
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                s.erase(nums[i]);
            } else {
                s.insert(nums[i]);
            }
        }
        return *s.begin();
    }
};