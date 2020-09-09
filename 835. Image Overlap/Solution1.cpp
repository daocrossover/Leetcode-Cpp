// Description:
// Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)
// We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image. 
// After, the overlap of this translation is the number of positions that have a 1 in both images.
// (Note also that a translation does not include any kind of rotation.)
// What is the largest possible overlap?

// Example 1:
// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.

// Notes: 
// 1. 1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 2. 0 <= A[i][j], B[i][j] <= 1

// Linear Transformation Solution:
// Time Complexity: O(n^4)
// Space Complexity: O(n^2)

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::pair;
using std::unordered_map;
using std::string;
using std::to_string;
using std::max;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int, int>> la, lb;
        // use two lists to save pixel coordinates
        for (int r = 0; r < A.size(); ++r) {
            for (int c = 0; c < A[0].size(); ++c) {
                if (A[r][c] == 1) la.push_back({r, c});
                if (B[r][c] == 1) lb.push_back({r, c});
            }
        }
        // map the vector (from a pixel in A to a pixel in B) to its count
        unordered_map<string, int> m;
        for (auto pa: la) {
            for (auto pb: lb) {
                string key = to_string(pa.first - pb.first) + " " + to_string(pa.second - pb.second);
                m[key]++; // count the number of same vectors
            }
        }
        int max_overlap = 0;
        for (auto kv: m) {
            max_overlap = max(max_overlap, kv.second);
        }
        return max_overlap;
    }
};