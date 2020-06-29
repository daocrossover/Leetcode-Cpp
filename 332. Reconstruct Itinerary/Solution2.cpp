// DFS, Recursive Solution:
// Hierholzer's Algorithm to get Euler circuit/path

#include <unordered_map>
#include <vector>
#include <string>
#include <set>
using std::unordered_map;
using std::vector;
using std::string;
using std::multiset;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); ++i) {
            graph[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }

private:
    unordered_map<string, multiset<string>> graph;
    vector<string> route;
    
    void dfs(string airport) {
        while (graph[airport].size() > 0) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }
        route.push_back(airport);
    }
};