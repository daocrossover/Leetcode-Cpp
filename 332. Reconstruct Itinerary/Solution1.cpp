// Description:
// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
// All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

// Note:
// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.

// Example 1:
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

// Example 2:
// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.

// DFS, Iterative Solution:

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
        unordered_map<string, multiset<string>> graph;
        for (int i = 0; i < tickets.size(); ++i) {
            graph[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> march = {"JFK"}; // the storage for greedy searching
        vector<string> res; // store the final results reversely
        while (!march.empty()) {
            string from = march.back();
            if ((graph.find(from) != graph.end()) && (!graph[from].empty())) { // march further
                march.push_back(*graph[from].begin());
                graph[from].erase(graph[from].begin());
            } else { // can not march further, trace back
                res.push_back(march.back()); // archive the last place
                march.pop_back();
            }
        }
        reverse(res.begin(), res.end()); // reverse the entries back
        return res;
    }
};