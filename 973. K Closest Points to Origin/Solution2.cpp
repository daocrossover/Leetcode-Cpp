// Quick Select Solution:
// The idea is the same as the quick sort (Divide and Conquer)
// Time Complexity: O(N) (average), O(N^2) (the worst)
// Space Complexity: O(N)

#include<vector>
#include<queue>
using std::vector;

class Solution {
private:
    int dist(const vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    int compare(const vector<int> point1, const vector<int> point2) {
        return dist(point1) - dist(point2);
    }
    
    int helper(vector<vector<int>>& points, int low, int high) {
        vector<int> pivot = points[low];
        while (low < high) {
            while (low < high && compare(points[high], pivot) >= 0) {
                high--;
            }
            points[low] = points[high];
            while (low < high && compare(points[low], pivot) <= 0) {
                low++;
            }
            points[high] = points[low];
        }
        points[low] = pivot;
        return low;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        int low = 0, high = points.size() - 1;
        while (low <= high) {
            int mid = helper(points, low, high);
            if (mid == K) {
                break;
            } else if (mid < K) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        while (K > 0) {
            res.push_back(points[--K]);
        }
        return res;
    }
};