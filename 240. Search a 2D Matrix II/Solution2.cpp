// binary search, O(mlogn)

#include<vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low =  mid + 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (target >= matrix[i][0] && target <= matrix[i][n-1]) {
                if (binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }
        return false;
    }
};