// Description:
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// The update(i, val) function modifies nums by updating the element at index i to val.

// Example:
// Given nums = [1, 3, 5]
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

// segment tree!

#include<vector>
using namespace std;

class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(2 * n);
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            tree[i] = nums[j]; 
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while (i > 1) {
            i /= 2;
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    int sumRange(int i, int j) {
        i += n;
        j += n;
        int sum = 0;
        while (i <= j) {
            if (i % 2 == 1) {
                sum += tree[i];
                i++;
            }
            if (j % 2 == 0) {
                sum += tree[j];
                j--;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */