// Sorting Solution:
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <vector>
using std::vector;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto a: intervals) {
            starts.push_back(a[0]);
            ends.push_back(a[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) {
                ++res; // need add new room
            } else {
                ++endpos; // insert meeting into the room with smallest end time
            }
        }
        return res;
    }
};
