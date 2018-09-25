// Binary Search Solution:
// The left-top element is the smallest and the right-down element is the largest
// Calculate the mid = average of them, then find the number of the elements which is <= mid
// Find from the left-bottom using the property of ascending order in the column

#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                // the element above matrix[i][j] also <= target 
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};