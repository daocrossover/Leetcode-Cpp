// Math Solution:
// G(n)= ∑ (1 <= i <= n) G(i−1)⋅G(n−i)
// G(n) -> Catalan number Cn
// Cn+1 =  2(2n+1)/(n+2) * Cn  C0 = 1

class Solution {
public:
    int numTrees(int n) {
        // use long here instead of int, otherwise overflow
        long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) C;
    }
};
