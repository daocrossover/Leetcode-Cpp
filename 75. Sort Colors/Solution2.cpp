// Counting Sort Solution:
// Time Complexity: O(n) two passes
// Space Complexity: O(m) m: number of different colors

#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) ++num0;
            else if (nums[i] == 1) ++num1;
            else if (nums[i] == 2) ++num2;
        }
        for(int i = 0; i < num0; ++i) nums[i] = 0;
        for(int i = 0; i < num1; ++i) nums[num0 + i] = 1;
        for(int i = 0; i < num2; ++i) nums[num0 + num1 +i ] = 2;
    }
};