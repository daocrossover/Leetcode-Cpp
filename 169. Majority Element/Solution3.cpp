// HashMap Solution:
// Time complexity: O(n)
// Space complexity: O(n)

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;
        for (int num: nums) {
            count[num]++;
            if (count[num] > nums.size() / 2) {
                res = num;
                break;
            }
        }
        return res;
    }
};