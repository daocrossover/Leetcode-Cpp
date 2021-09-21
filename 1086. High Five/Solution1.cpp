// 1086. High Five
// Description:
// Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.
// Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.
// A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.

// Example 1:
// Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
// Output: [[1,87],[2,88]]
// Explanation:
// The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
// The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.

// Example 2:
// Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
// Output: [[1,100],[7,100]]

// Constraints:
// 1. 1 <= items.length <= 1000
// 2. items[i].length == 2
// 3. 1 <= IDi <= 1000
// 4. 0 <= scorei <= 100
// 5. For each IDi, there will be at least five scores.

// Map + Min-heap (priority queue)
// The key is the id of each person, 
// and the value is a priority queue to store each person's top five scores.

#include <vector>
#include <queue>
#include <map>
using std::vector;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        std::map<int, std::priority_queue<int, vector<int>, std::greater<int>>> scores;
        int id, score;
        for (auto& i : items) {
            id = i[0];
            score = i[1];
            scores[id].push(score);
            if (scores[id].size() > 5) {
                scores[id].pop();
            }
            // if (scores[id].size() < 5) {
            //     scores[id].push(score);
            // } else if(scores[id].size() == 5 && scores[id].top() < score) {
            //     scores[id].pop();
            //     scores[id].push(score);
            // }
        }
        for (auto& it : scores) {
            id = it.first;
            int sum = 0;
            while (!scores[id].empty()) {
                sum += scores[id].top();
                scores[id].pop();
            }
            res.push_back({id, sum / 5});
        }
        return res;
    }
};