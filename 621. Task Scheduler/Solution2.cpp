// Priority Queue Solution:

#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::make_pair;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (char t: tasks) {
            count[t]++;
        }
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> c: count) {
            pq.push(make_pair(c.second, c.first));
        }
        int alltime = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<pair<int, char>> tmp;
            while (cycle > 0 && !pq.empty()) {
                tmp.push_back(pq.top()); // most frequency task and add back to queue 
                pq.pop();
                cycle--; 
                alltime++; // successfully executed task
            }
            // decrease the frequency, and put them back after the round.
            for (pair<int, char> t: tmp) {
                if (--t.first > 0) {
                    pq.push(t); // add valid tasks
                }
            }
            if (pq.empty()) break;
            alltime += cycle; // if cycle > 0, then it means we need to be idle
        }
        return alltime;
    }
};