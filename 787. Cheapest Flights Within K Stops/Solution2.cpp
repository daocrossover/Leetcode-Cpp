// Dijkstra's Algorithm Solution:
// Using priority queue as min heap

#include<vector>
#include<unordered_map>
#include<queue>
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::min;

class Solution {
private:
    class City {
    public:
        int city, dist, cost;
        City(int city, int dist, int cost) {
            this->city = city;
            this->dist = dist;
            this->cost = cost;
        }
        // overload the operator
        friend bool operator< (const City &a, const City &b) { return a.cost < b.cost; }
        friend bool operator> (const City &a, const City &b) { return a.cost > b.cost; }
    };
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int>& v: flights) {
            graph[v[0]].push_back(make_pair(v[1], v[2]));
        }
        // Using min heap
        priority_queue<City, vector<City>, greater<vector<City>::value_type>> pq;
        pq.push(City(src, 0, 0));
        while (!pq.empty()) {
            City cur = pq.top();
            pq.pop();
            if (cur.city == dst) {
                return cur.cost;
            }
            if (cur.dist > K) {
                continue;
            }
            for (pair<int, int>& neighbor : graph[cur.city]) {
                pq.push(City(neighbor.first, cur.dist + 1, cur.cost + neighbor.second));
            }
        }
        return -1;
    }
};