// Description:
// Suppose you have a random list of people standing in a queue.
// Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
// Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

// Example
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// Greedy Solution (Sorting):
// Time Complexity: O(n^2) (insertion)
// Space Complexity: O(n)

#include <vector>
using std::vector;

class Solution {
public:
    static bool cmp (const vector<int>& p1, const vector<int>& p2) {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        /* or using lambda function:
            sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            });
        */
        vector<vector<int>> res;
        for (vector<int> p: people) {
            // insert the element according to the k value
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};