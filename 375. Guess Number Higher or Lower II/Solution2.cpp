// Dynamic Programming Solution: bottom-up

#include<vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> table(n+1, vector<int>(n+1));
        for (int j = 2; j <= n; ++j) {
            for (int i = j-1; i > 0; --i) {
                int globalMin = INT_MAX;
                for (int k = i+1; k < j; ++k) {
                    int localMax = k + max(table[i][k-1], table[k+1][j]);
                    globalMin = min(globalMin, localMax);
                }
                table[i][j] = i+1 == j ? i : globalMin;
            }
        }
        return table[1][n];
    }
};