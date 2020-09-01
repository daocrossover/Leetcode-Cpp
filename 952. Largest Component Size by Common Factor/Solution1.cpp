// Description:
// Given a non-empty array of unique positive integers A, consider the following graph:
// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.

// Example 1:
// Input: [4,6,15,35]
// Output: 4

// Example 2:
// Input: [20,50,9,63]
// Output: 2

// Example 3:
// Input: [2,3,6,7,4,12,21,39]
// Output: 8

// Note:
// 1. 1 <= A.length <= 20000
// 2. 1 <= A[i] <= 100000

// Union-Find Solution:

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::sqrt;
using std::max;

// Weighted Quick-Union With Path Compression
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // path compression
    int Find(int x) {
        if (x != parent[x]) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int p, int q) {
        int p_root = Find(p);
        int q_root = Find(q);
        if (p_root == q_root) return;
        if (size[p_root] < size[q_root]) {
            parent[p_root] = q_root;
            size[q_root] += size[p_root];
        } else {
            parent[q_root] = p_root;
            size[p_root] += size[q_root];
        }
    }
    
private:
    vector<int> parent, size;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end()); // find the max element in A
        UnionFind uf(n + 1);
        for (int a: A) {
            for (int f = 2; f <= sqrt(a); ++f) {
                // union each element with all its factor
                if (a % f == 0) {
                    uf.Union(a, f);
                    uf.Union(a, a / f);
                }
            }
        }
        // count the most frequent parent
        unordered_map<int, int> m;
        int res = 1;
        for (int a: A) {
            res = max(res, ++m[uf.Find(a)]);
        }
        return res;
    }
};