#include<climits>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32; //n = 2^31-1;
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0) n /= 2;
            else {
                if ((n + 1) % 4 == 0 && (n - 1 != 2)) n++;
                else n--;
            }
            count++;
        }
        return count;
    }
};