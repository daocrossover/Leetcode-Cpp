// Description:
// Given a n x n matrix where each of the rows and columns are sorted in ascending order,
// find the kth smallest element in the matrix.
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example:
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
// return 13.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n^2.

// Priority Queue Solution:
// build a min-heap of elements from the first row
// Do the following operations k-1 times:
// 1. pop an element t from the heap
// 2. push the next element of t in the same column to the heap
// So we need to record the coordinate x, y and val(using tuple)
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

class Solution {
    typedef tuple<int, int, int> tu;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tu, vector<tu>, greater<tu>> pq;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; ++i) pq.push(make_tuple(matrix[0][i], 0, i));
        for (int i = 0; i < k - 1; ++i) {
            auto t = pq.top();
            pq.pop();
            if (get<1>(t) == m-1)
                continue;
            pq.push(make_tuple(matrix[get<1>(t)+1][get<2>(t)], get<1>(t)+1, get<2>(t)));
        }
        return get<0>(pq.top());
    }
};