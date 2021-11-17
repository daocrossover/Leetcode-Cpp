// 927. Three Equal Parts
// Description:
// You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts 
// such that all of these parts represent the same binary value.

// If it is possible, return any [i, j] with i + 1 < j, such that:
// arr[0], arr[1], ..., arr[i] is the first part,
// arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
// arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
// All three parts have equal binary values.

// If it is not possible, return [-1, -1].

// Note that the entire part is used when considering what binary value it represents. 
// For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

// Example 1:
// Input: arr = [1,0,1,0,1]
// Output: [0,3]

// Example 2:
// Input: arr = [1,1,0,1,1]
// Output: [-1,-1]

// Example 3:
// Input: arr = [1,1,0,0,1]
// Output: [0,2]

// Constraints:
// 3 <= arr.length <= 3 * 10^4
// arr[i] is 0 or 1

// Solution: Equal Ones
// Count number of 1's in the given array, if count == 0, return {0, n - 1}
// if count % 3 != 0, we can't partition the array
// Then, find the first 1 in the array (p[0]), and we know each part should have k = count / 3 ones
// We could find the (k + 1)th and (2k + 1)th one in the array
// Finally, match all values using three pointers till the end of the array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int one_count = 0;
        for (int a : arr) {
            one_count += a;
        }
        int n = arr.size();
        if (one_count == 0) {
            return {0, n - 1};
        } else if (one_count % 3 != 0) {
            return {-1, -1};
        }
        
        int k = one_count / 3;
        int p[3] = {0};
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                if (count % k == 0) {
                    p[count / k] = i;
                }
                count++;
            } 
        }
        
        while (p[2] < n && arr[p[0]] == arr[p[1]] && arr[p[1]] == arr[p[2]]) {
            p[0]++;
            p[1]++;
            p[2]++;
        }
        if (p[2] == n) {
            return {p[0] - 1, p[1]};
        }
        return {-1, -1};
    }
};