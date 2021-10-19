// 1606. Find Servers That Handled Most Number of Requests
// Description:
// You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. 
// Each server has infinite computational capacity but cannot handle more than one request at a time. 
// The requests are assigned to servers according to a specific algorithm:

// 1. The ith (0-indexed) request arrives.
// 2. If all servers are busy, the request is dropped (not handled at all).
// 3. If the (i % k)th server is available, assign the request to that server.
// 4. Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). 
// For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.

// You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, 
// and another array load, where load[i] represents the load of the ith request (the time it takes to complete). 
// Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

// Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.

// Example 1:
// Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
// Output: [1] 
// Explanation:
// All of the servers start out available.
// The first 3 requests are handled by the first 3 servers in order.
// Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
// Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
// Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.

// Example 2:
// Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
// Output: [0]
// Explanation:
// The first 3 requests are handled by first 3 servers.
// Request 3 comes in. It is handled by server 0 since the server is available.
// Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.

// Example 3:
// Input: k = 3, arrival = [1,2,3], load = [10,12,11]
// Output: [0,1,2]
// Explanation: Each server handles a single request, so they are all considered the busiest.

// Example 4:
// Input: k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
// Output: [1]

// Example 5:
// Input: k = 1, arrival = [1], load = [1]
// Output: [0]

// Constraints:
// 1 <= k <= 10^5
// 1 <= arrival.length, load.length <= 10^5
// arrival.length == load.length
// 1 <= arrival[i], load[i] <= 10^9
// arrival is strictly increasing.

// PriorityQueue + Ordered Set Solution:
// Time Complexity: O(nlogk)
// Space Complexity: O(k)

#include <vector>
#include <set>
#include <queue>
using std::vector;
using std::set;
using std::priority_queue;
using std::pair;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k); // counting the number of requests for each server
        set<int> available; // containing the index of available servers.
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        // pq: min-heap and pair: (end_time, server_index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> busy;
        for (int i = 0; i < arrival.size(); ++i) {
            int cur_time = arrival[i];
            int end_time = cur_time + load[i];
            // Free all the servers from busy whose end_time is smaller than or equal to cur_time
            while (!busy.empty() && cur_time >= busy.top().first) {
                int server = busy.top().second;
                busy.pop();
                available.insert(server);
            }
            // If all servers are busy, the request is dropped
            if (available.empty()) {
                continue;
            }
            // find the first element which has a value not less than i % k
            auto it = available.lower_bound(i % k);
            // If not found, find from 0 to k (the first element in the ordered set)
            if (it == available.end()) {
                it = available.begin();
            }
            // when finding an available server
            count[*it]++;
            busy.push(std::make_pair(end_time, *it)); // put (end_time, server_index) to pq
            available.erase(*it); // erase it from available set
        }
        vector<int> res;
        // find all the Maxes in the Counter
        int max_num = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_num) {
                res.push_back(i);
            }
        }
        return res;
    }
};