// Description:
// Given a collection of intervals, merge all overlapping intervals.

// Example 1:
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Example 2:
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.


// Sorting Solution:
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include<vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool myfunction(Interval i, Interval j) {
        return (i.start < j.start);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), myfunction);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > res.back().end) {
                // if the current interval does not overlap with the previous, append it.
                res.push_back(intervals[i]);
            } else {
                // otherwise, there is overlap, merge the current and previous intervals.
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};