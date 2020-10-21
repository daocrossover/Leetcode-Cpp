// 547. Friend Circles
// Description:
// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
// For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. 
// And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation: The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.

// Example 2:
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation: The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

// Constraints:
// 1. 1 <= N <= 200
// 2. M[i][i] == 1
// 3. M[i][j] == M[j][i]

// Union-Find Solution:

#include <vector>
using std::vector;

class UnionFind {
public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
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
        count--;
    }
    
    int get_count() {
        return count;
    }

private:
    vector<int> parent, size;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    uf.Union(i, j);
                }
            }
        }
        return uf.get_count();
    }
};