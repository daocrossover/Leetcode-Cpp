// the answer is therefore the sum of these prime factors.
// Time Complexity: O(sqrt(N)) When N is the square of a prime.
// Space Complexity: O(1)

class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }
};