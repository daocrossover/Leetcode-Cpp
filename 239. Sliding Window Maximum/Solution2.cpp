// using deque
// time complexity: O(n), space complexity: O(k)

#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            // when access new nums[i], if index of deque front is equal to index of window left, pop it
            if (!q.empty() && q.front() == i - k) q.pop_front();
            // delete all elements which is less than nums[i] from deque back
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            // add new nums[i] to deque
            q.push_back(i);
            // the deque front is the max in the window
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};