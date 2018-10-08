// Dynamic Programming: bottom-up

#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // use a new array to store minSum
        vector<int> res = triangle.back();
        for (int i = triangle.size()-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                res[j] = triangle[i][j] + min(res[j], res[j+1]);
            }
        }
        return res[0];
    }
};