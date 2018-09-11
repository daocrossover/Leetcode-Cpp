// Description
// Find the total area covered by two rectilinear rectangles in a 2D plane.
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Example:
// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45

// Note:
// Assume that the total area is never beyond the maximum possible value of int.

#include<vector>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = 0;
        if (C < E || G < A || B > H || F > D) {
            overlap = 0;
        } else {
            vector<int> a = {A, C, E, G};
            vector<int> b = {B, D, F, H};
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            overlap = (a[2] - a[1]) * (b[2] - b[1]);
        }
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};