// Description:
// Given two arrays of length m and n with digits 0-9 representing two numbers.
// Create the maximum number of length k <= m + n from digits of the two.
// The relative order of the digits from the same array must be preserved.
// Return an array of the k digits.

// Note: You should try to optimize your time and space complexity.

// Example 1:
// Input:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// Output:
// [9, 8, 6, 5, 3]

// Example 2:
// Input:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// Output:
// [6, 7, 6, 0, 4]

// Example 3:
// Input:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// Output:
// [9, 8, 9]

#include<vector>
using namespace std;

class Solution {
public:
    // find subsequence with k largest elements in an array in order
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0) return res;
        int to_pop = nums.size() - k;
        for (int i = 0; i < nums.size(); ++i) {
            while (!res.empty() && res.back() < nums[i] && to_pop-- > 0) {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        return res;
    }
    
    bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        if (j == nums2.size()) return true;
        if (i < nums1.size() && nums1[i] > nums2[j]) return true;
        return false;
    }

    // merge two arrays into an array with k elements
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> res(k, 0);
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(k);
        // if k < n, nums1 -> (0, k) nums2 -> (k, 0)
        // if k > n, nums1 -> (k-n, k) nums2 -> (n, 0)
        for (int i = max(0, k - n); i <= k && i <= m; ++i) {
            // find the max candidate
            vector<int> candidate = move(merge(maxArray(nums1, i), maxArray(nums2, k - i), k));
            if (compare(candidate, 0, res, 0)) res = move(candidate);
        }
        return res;
    }
};