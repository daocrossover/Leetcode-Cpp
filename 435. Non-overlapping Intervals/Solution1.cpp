// Description:
// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

// Example 1:
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// Output: 1
// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

// Example 2:
// Input: [ [1,2], [1,2], [1,2] ]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

// Example 3:
// Input: [ [1,2], [2,3] ]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Greedy Solution: Sorting
// The question is the same as Interval Scheduling Problems.

#include <vector>
using std::vector;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, end = INT_MIN;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; // sorting Interval.end in ascending order
        });
        for (vector<int> i: intervals) {
            if (i[0] >= end) {
                end = i[1];
            } else {
                res++;
            }
        }
        return res;
    }
};