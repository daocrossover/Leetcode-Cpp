// 774. Minimize Max Distance to Gas Station
// Description:
// On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.
// Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
// Return the smallest possible value of D.

// Example:
// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
// Output: 0.500000

// Note:
// 1. stations.length will be an integer in range [10, 2000].
// 2. stations[i] will be an integer in range [0, 10^8].
// 3. K will be an integer in range [1, 10^6].
// 4. Answers within 10^-6 of the true value will be accepted as correct.

// Hints:
// Use a binary search. We'll binary search the monotone function "possible(D) = can we use K or less gas stations to ensure each adjacent distance between gas stations is at most D?"

// Binary Search:
// Find the optimal D* in [0, 10^8] using binary search to satisfy the requirement
// When we have some interval like X = stations[i+1] - stations[i] , we need to use ⌊X/D⌋ gas stations to ensure every subinterval has size less than D. 
// This is independent of other intervals, so in total we need to use sum_i(⌊Xi/D⌋) gas stations. 
// If this is at most K, then it is possible to make every adjacent distance between gas stations at most D.

#include <vector>
using std::vector;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (possible(stations, K, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
    bool possible(vector<int>& stations, int K, double mid) {
        int cnt = 0, n = stations.size();
        for (int i = 0; i < n - 1; ++i) {
            cnt += (stations[i + 1] - stations[i]) / mid;
        }
        return cnt <= K;
    }
};