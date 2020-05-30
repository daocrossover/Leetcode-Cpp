// Description:
// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
// Check if these points make a straight line in the XY plane.

// Example 1:
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

// Example 2:
// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false

// Constraints:
// 1. 2 <= coordinates.length <= 1000
// 2. coordinates[i].length == 2
// 3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
// 4. coordinates contains no duplicate point.

#include<vector>
using std::vector;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            // Use cross product to check collinearity
            // (y - y1) / (x - x1) = (y2 - y1) / (x2 - x1)
            // (y - y1) * (x2 - x1) = (y2 - y1) * (x - x1)
            int x = coordinates[i][0], y = coordinates[i][1];    
            if ((y - y1) * (x2 - x1) != (y2 - y1) * (x - x1)) {
                return false;
            }
        }
        return true;
    }
};