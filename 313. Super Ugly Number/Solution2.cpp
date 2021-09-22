// Solution2: Min-Heap (priority queue)
// keep the one candidates for each prime in a heap
// heap stores {num, prime, index}
// Time Complexity: theoretically O(nlogk)
// But due to the duplicates, will TLE
// Also need to use long long to avoid INT overflow
// case:
// n = 1000000
// primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541]

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::min;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> ugly(n);
        ugly[0] = 1;
        auto cmp = [](vector<long long>& a, vector<long long>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp)> pq(cmp);
        for (int j = 0; j < len; ++j) {
            pq.push(vector<long long>{primes[j], primes[j], 1});
        }
        for (int i = 1; i < n; ++i) {
            ugly[i] = pq.top()[0];
            while (pq.top()[0] == ugly[i]) {
                vector<long long> cur = pq.top();
                pq.pop();
                pq.push(vector<long long>{cur[1] * ugly[cur[2]], cur[1], cur[2] + 1});
            }
        }
        return ugly[n-1];
    }
};