// 939. Minimum Area Rectangle
// Description:
// You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
// Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. 
// If there is not any such rectangle, return 0.

// Example 1:
// Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
// Output: 4

// Example 2:
// Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// Output: 2

// Constraints:
// 1 <= points.length <= 500
// points[i].length == 2
// 0 <= xi, yi <= 4 * 10^4
// All the given points are unique.

// HashMap + HashSet Solution:
// Given two points A and B of a diagonal, 
// C     B
// A     D
// we can calculate the remaining two points of the second diagonal.
// C.x == A.x && C.y == B.y
// D.x == B.x && D.y == A.y
// To find y sets given fixed x value, using hashset will be O(1). 
// Therefore, the values of HashMap is HashSets
// Key => Different x coordinates
// Value => HashSet of y coordinates of points having same x coordinate
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// where n = total number of points

#include <vector>
#include <unordered_set>
#include <unordered_map>
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> coordinates;
        for (auto &point : points) {
            coordinates[point[0]].insert(point[1]);
        }
        
        int min_area = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];  // Coordinates of Point A
				int x2 = points[j][0], y2 = points[j][1];  // Coordinates of Point B
                if (x1 != x2 && y1 != y2) {
                    // Point A & B must form a diagonal of the rectangle.
                    if (coordinates[x1].find(y2) != coordinates[x1].end() && coordinates[x2].find(y1) != coordinates[x2].end()) {
                        min_area = std::min(min_area, abs(x1 - x2) * abs(y1 - y2));
                    }
                }

            }
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};