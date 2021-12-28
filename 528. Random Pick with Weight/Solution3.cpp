// Using map (TreeMap)

#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
    Solution(vector<int>& w) {
        total_weight = 0;
        for (int i = 0; i < w.size(); ++i) {
            total_weight += w[i];
            weight_map[total_weight] = i;
        }
    }
    
    int pickIndex() {
        int x = rand() % total_weight;
        return weight_map.upper_bound(x)->second;
    }
    
private:
    map<int, int> weight_map;
    int total_weight;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */