// Description:
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
// find the minimum number of conference rooms required.

// Example 1:
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2

// Example 2:
// Input: [[7,10],[2,4]]
// Output: 1

// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

// Sorting and MinHeap Solution:
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto interval: intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop(); // the last meeting is ending, could use the same room
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};