// BFS Solution:

#include <vector>
#include <queue>
using std::vector;
using std::queue;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            if (f >= low && f <= high) {
                res.push_back(f);
            }
            if (f > high) break;
            int num = f % 10;
            if (num < 9) {
                q.push(f * 10 + num + 1);
            }
        }
        return res;
    }
};