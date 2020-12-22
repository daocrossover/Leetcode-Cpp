// 1353. Maximum Number of Events That Can Be Attended
// Description:
// Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where startTimei <= d <= endTimei. 
// Notice that you can only attend one event at any time d.
// Return the maximum number of events you can attend.

// Example 1:
// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.

// Example 2:
// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4

// Example 3:
// Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
// Output: 4

// Example 4:
// Input: events = [[1,100000]]
// Output: 1

// Example 5:
// Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
// Output: 7
 
// Constraints:
// 1 <= events.length <= 10^5
// events[i].length == 2
// 1 <= startDayi <= endDayi <= 10^5

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // sort the events by the start time in ascending order.
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq; // keep the current open events
        int i = 0, n = events.size(), cur = 0, count = 0;
        while (!pq.empty() || i < n) {
            if (pq.empty()) {
                cur = events[i][0];
            }
            while (i < n && events[i][0] == cur) {
                pq.push(events[i][1]); // add new events that can attend on day 'cur'
                i++;
            }
            // greedily attend the event that ends soonest
            pq.pop();
            cur++;
            count++; // if we can attend a meeting, increment the count
            while (!pq.empty() && pq.top() < cur) {
                pq.pop(); // remove the events that are already closed
            }
        }
        return count;
    }
};