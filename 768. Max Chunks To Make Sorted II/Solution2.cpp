// PreSum + Sorting Solution:
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <vector>
using std::vector;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long sum1 = 0, sum2 = 0, res = 0;
        vector<int> t = arr;
        sort(t.begin(), t.end());
        for (int i = 0; i < arr.size(); ++i) {
            sum1 += t[i];
            sum2 += arr[i];
            if (sum1 == sum2) {
                res++;
            }
        }
	    return res;
    }
};