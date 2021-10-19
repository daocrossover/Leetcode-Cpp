// 2. Track travel days
// Dynamic Programming
// Time Complexity: O(n), where n is the number of travel days.
// Space Complexity: O(38). Stricter, it's a sum of duration for all pass types (1 + 7 + 30 in our case).

#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::pair;
using std::min;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> last7, last30;
        int cost = 0;
        for (int d: days) {
            while (!last7.empty() && last7.front().first + 7 <= d) last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= d) last30.pop();
            last7.push({d, cost + costs[1]});
            last30.push({d, cost + costs[2]});
            cost = min({cost + costs[0], last7.front().second, last30.front().second});
        }
        return cost;
    }
};