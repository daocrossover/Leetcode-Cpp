// Quick Select to find the median and three-partition
// Time Complexity: O(n) (worst: O(n^2))
// Space Complexity: O(n)

#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size(), m = (n + 1) / 2;
        vector<int> copy(nums);
        int median = quickSelect(copy, m);
        // three-partition on copy, [less than median, equal to median, large than median]
        for (int i = 0, j = 0, k = n - 1; j <= k;) {
            if (copy[j] < median) {
                swap(copy[i++], copy[j++]);
            } else if (copy[j] > median) {
                swap(copy[j], copy[k--]);
            } else {
                j++;
            }
        }
        for (int i = m - 1, j = 0; i >= 0; i--, j += 2) {
            nums[j] = copy[i];
        }
        for (int i = n - 1, j = 1; i >= m; i--, j += 2) {
            nums[j] = copy[i];
        }
        
        // for (int i = 0, j = 0, k = n - 1; j <= k;) {
        //     if (nums[A(j, n)] > median) {
        //         swap(nums[A(i++, n)], nums[A(j++, n)]);
        //     } else if (nums[A(j, n)] < median) {
        //         swap(nums[A(j, n)], nums[A(k--, n)]);
        //     } else {
        //         j++;
        //     }
        // }
    }

private:
    int quickSelect(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int j = partition(nums, low, high);
            if (j < k) {
                low = j + 1;
            } else if (j > k) {
                high = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
    
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot) --high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    
    // TODO:
    // virtual indexing
    int A(int i, int n) {
        return (2 * i + 1) % (n | 1);
    }
};