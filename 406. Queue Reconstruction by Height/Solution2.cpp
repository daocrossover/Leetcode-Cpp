// Greedy Solution (Sorting):
// Time Complexity: O(n^2) (insertion sorting idea)
// Space Complexity: O(1) (no extra array)

#include<vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] != b[0] ? b[0] < a[0] : a[1] < b[1];
        });
        for (int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (cnt == people[i][1]) {
                    vector<int> tmp = people[i];
                    for (int k = i - 1; k >= j; --k) {
                        people[k + 1] = people[k];
                    }
                    people[j] = tmp;
                    break;
                }
                cnt++;
            }
        }
        return people;
    }
};