// DFS, Recursive Solution:

#include<unordered_map>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
    unordered_map<string, multiset<string>> hash;
    vector<string> route;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (int i = 0; i < tickets.size(); ++i) {
            hash[tickets[i].first].insert(tickets[i].second);
        }
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }

    void dfs(string airport) {
        while (hash[airport].size()) {
            string next = *hash[airport].begin();
            hash[airport].erase(hash[airport].begin());
            dfs(next);
        }
        route.push_back(airport);
    }
};