// If there is no height range constraint
// find the maximum height and use the count sorting again

#include <vector>
using std::vector;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int max_height = 0;
        for (int h: heights) {
            if (h > max_height) {
                max_height = h;
            }
        }
        vector<int> count(max_height + 1, 0);
        for (int h: heights) {
            count[h]++;
        }
        int res = 0, i = 1;
        for (int h: heights) {
            while (count[i] == 0) {
                i++;
            }
            if (i != h) {
                res++;
            }
            count[i]--;
        }
        return res;
    }
};