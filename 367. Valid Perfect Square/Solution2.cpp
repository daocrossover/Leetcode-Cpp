// A square number is 1+3+5+7+...
// an = 2n - 1
// S = (1 + 2n - 1) * n / 2 = n^2
// Time Complexity: O(sqrt(n))

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};