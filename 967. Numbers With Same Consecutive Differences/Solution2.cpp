// Iterative Solution (BFS):

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> cur = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= N; ++i) {
            vector<int> tmp;
            for (int x : cur) {
                int y = x % 10; // last digit of cur
                if (x > 0 && y + K < 10) {
                    tmp.push_back(x * 10 + y + K);
                }
                if (x > 0 && K > 0 && y - K >= 0) {
                    tmp.push_back(x * 10 + y - K);
                } 
            }
            cur = tmp;
        }
        return cur;
    }
};