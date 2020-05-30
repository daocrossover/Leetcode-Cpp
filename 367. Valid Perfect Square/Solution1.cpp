// Binary Search Solution:
// Time Complexity: O(logn)

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            // using long to avoid overflow
            long mid = low + (high - low) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                low = (int)mid + 1;
            } else {
                high = (int)mid - 1;
            }
        }
        return false;
    }
};