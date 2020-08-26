// One-pass Solution:
// Using up and down to count the steps of continuous up and down respectively
// peak representing the peak before going down
// example:
// [0, 1, 20, 9, 8, 7]
// Scan from left to right, first child is given 1 candy;
// the second child is given 2 candies, and up=1;
// the third child is given 3 candies, and up=2; peak=2;
// the fourth child is given 1 candy, and down=1; and third child still has 3 candies since peak=2;
// the fifth child is given 1 candy, and down=2; and the previous child needs 1 more candy now but the third child no need more;
// the sixth child is given 1 candy, and down=3; and both the fifth and fourth child needs 1 more candy now, and the peak, the third child need 1 more as well.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        int res = 1;
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                peak = ++up;
                down = 0;
                res += 1 + up;
            } else if (ratings[i - 1] == ratings[i])  {
                peak = up = down = 0;
                res += 1;
            } else {
                up = 0;
                down++;
                // when peak >= down, the candies for the peak still don't need to change.
                res += 1 + down + (peak >= down ? -1 : 0);
            }
        }
        return res;
    }
};