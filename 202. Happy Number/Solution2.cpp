// Fast and Slow Pointers Solution
// In order to find the cycle

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (fast != 1 && nextNumber(fast) != 1) {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
            if (slow == fast) break;
        }
        return fast == 1 || nextNumber(fast) == 1;
    }
    
    int nextNumber(int n) {
        int sum = 0;
        int digit = 0;
        while (n > 0) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};