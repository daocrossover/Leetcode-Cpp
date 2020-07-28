// Description:
// You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. 
// Tasks could be done without the original order of the array. 
// Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
// You need to return the least number of units of times that the CPU will take to finish all the given tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.

// Example 2:
// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6
// Explanation: On this case any permutation of size 6 would work since n = 0.
// ["A","A","A","B","B","B"]
// ["A","B","A","B","A","B"]
// ["B","B","B","A","A","A"]
// ...
// And so on.

// Example 3:
// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16
// Explanation: 
// One possible solution is
// A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 
// Constraints:
// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

// Greedy Solution:
// Focus on the the max number of one task and
// set apart each max task with interval n, and we hope to put all other tasks into those intervals.
// pay attention to existense of multiple max tasks.
// eg. 3 A, 3 B, 2 C, 1 D, n = 3
// A B ? ? A B ? ? A B
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        int max_num = 0, max_count = 0;
        for (char t: tasks) {
            count[t - 'A']++;
            if (max_num < count[t - 'A']) {
                max_num = count[t - 'A'];
                max_count = 1;
            } else if (max_num == count[t - 'A']) {
                max_count++;
            }
        }
        
        int part_count = max_num - 1; // number of empty slot parts
        int part_len = n - (max_count - 1); // empty slot part length
        int slots = part_count * part_len; // total empty slot number
        int available_tasks = tasks.size() - max_num * max_count; // left tasks 
        int idles = max(slots - available_tasks, 0);
        return tasks.size() + idles;
    }
};