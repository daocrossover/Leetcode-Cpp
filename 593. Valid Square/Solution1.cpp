// Description:
// Given the coordinates of four points in 2D space, return whether the four points could construct a square.
// The coordinate (x,y) of a point is represented by an integer array with two integers.

// Example:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: True
 
// Note:
// 1. All the input integers are in the range [-10000, 10000].
// 2. A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 3. Input points have no order.

// Sorting Solution:
// p0p1, p1p3, p3p2, and p2p0 form the four sides of any valid square.
// p0p3 and p1p2 form the diagonals of the square.

#include <vector>
using std::vector;

class Solution {
private:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        sort(p.begin(), p.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) && dist(p[1], p[3]) == dist(p[3], p[2]) && dist(p[3], p[2]) == dist(p[2], p[0]) && dist(p[0], p[3]) == dist(p[1], p[2]);
    }
};