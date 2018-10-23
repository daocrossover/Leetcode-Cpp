// Description:
// Given a set of non-overlapping intervals,
// insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        // put all intervals that are to the left of the inserted interval
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            res.push_back(intervals[i]);
            i++;
        }
        // merge all intervals that intersect with the inserted interval
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        res.push_back(newInterval);
        // put all intervals that are to the right of the inserted interval
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};