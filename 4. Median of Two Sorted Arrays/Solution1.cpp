// 4. Median of Two Sorted Arrays
// Description:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log(m + n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Example 3:
// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000

// Example 4:
// Input: nums1 = [], nums2 = [1]
// Output: 1.00000

// Example 5:
// Input: nums1 = [2], nums2 = []
// Output: 2.00000

// Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6

// Binary Search Solution:
// nums1: A0, A1, ... , Am1-1, Am1, ... , Am-1
// nums2: B0, B1, ... m Bn1-1, Bn1, ... , Bn-1
// combined: C0, C1, C2, ... , Ck-1, Ck, ... , Cm+n-1
// m1 + n1 = k = (m + n + 1) / 2
// Median must from {Am1-1, Am1, Bn1-1, Bn1}
// Ck-1 = max(Am1-1, Bn1-1)
// Ck = min(Am1, Bn1)
// Time Complexity: O(log(min(m, n)))

#include <vector>
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // Make sure m <= n
        if (n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        // k is the index of the right median number in the combined array
        int k = (m + n + 1) / 2;
        
        // binary search m1 to get the approximate location of median
        // based on nums1[m1] < nums2[n1 - 1]?
        int l = 0, r = m;
        while (l < r) {
            int m1 = l + (r - l) / 2;
            int n1 = k - m1;
            if (nums1[m1] < nums2[n1 - 1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }

        // After binary search, we almost get the median because it must be between
        // these 4 numbers: Am1-1, Am1, Bn1-1, Bn1
        // there are some corner cases we need to take care of
        int m1 = l, n1 = k - l;
        int c1 = std::max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], n1 <= 0 ? INT_MIN : nums2[n1 - 1]);
        // if (m + n) is odd, the median is the larger one between Am1-1 and Bn1-1
        if ((m + n) % 2 == 1) {
            return c1;
        }

        // If (m + n) is even, the median can be calculated by (ck-1 + ck) / 2.0
        // there are some corner cases we need to take care of
        int c2 = std::min(m1 >= m ? INT_MAX : nums1[m1], n1 >= n ? INT_MAX : nums2[n1]); 
        return (c1 + c2) * 0.5;
    }
};