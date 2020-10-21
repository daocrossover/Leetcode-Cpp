// Using treemap instead of sorting

#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t: trips) {
            m[t[1]] += t[0];
            m[t[2]] -= t[0];
        }
        for (auto &p: m) {
            capacity -= p.second;
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
};