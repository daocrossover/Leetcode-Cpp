// Description:
// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number).
// Given some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries ,
// where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

// turn into a graph, and the question is turned to find a path from start to end

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // build the graph
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i].first][equations[i].second] = values[i];
            graph[equations[i].second][equations[i].first] = 1 / values[i];
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            double tmp = 1;
            unordered_set<string> visited;
            if (graph.find(queries[i].first) != graph.end() && 
                graph.find(queries[i].first) != graph.end() &&
                dfs(queries[i].first, queries[i].second, tmp, graph, visited)) {
                res.push_back(tmp);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
    
    bool dfs(string cur, string end, double& res, unordered_map<string, unordered_map<string, double>> graph, unordered_set<string>& visited) {
        if (visited.find(cur) != visited.end())
            return false;
        if (cur == end)
            return true;
        visited.insert(cur);
        for (auto neighbor : graph[cur]) {
            string next = neighbor.first;
            res *= neighbor.second;
            if (dfs(next, end, res, graph, visited))
                return true;
            res /= neighbor.second;
        }
        visited.erase(cur);
        return false;
    }
};