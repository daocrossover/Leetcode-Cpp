// Maximum sum rectangle in a 2D matrix

// Kadane's Algorithm Solution:
// Keep temp array with size as number of rows. Start left and right from 0
// and keep adding values for each row and maintain them in this temp array.
// Run Kadane's algorithm to find max sum subarray in temp. Now increment right by 1.
// When right reaches last column reset right to 1 and left to 1.
// Time Complexity: O(mn^2), Space Complexity: O(m)

#include<vector>
using namespace std;

class Solution {
public:
    int kadane(vector<int>& nums, int& start, int& finish, int n) {
        // initialize sum, maxSum and 
        int sum = 0, maxSum = INT_MIN; 
        // Just some initial value to check for all negative values case 
        finish = -1; 
        // local variable 
        int local_start = 0; 
        for (int i = 0; i < n; ++i) { 
            sum += nums[i]; 
            if (sum < 0) { 
                sum = 0; 
                local_start = i + 1; 
            } else if (sum > maxSum) { 
                maxSum = sum; 
                start = local_start; 
                finish = i; 
            } 
        } 
        // There is at-least one non-negative number 
        if (finish != -1) return maxSum; 
        // Special Case: When all numbers in arr[] are negative 
        maxSum = nums[0]; 
        start = finish = 0; 
        // Find the maximum element in array 
        for (int i = 1; i < n; i++) { 
            if (nums[i] > maxSum) { 
                maxSum = nums[i]; 
                start = finish = i; 
            } 
        } 
        return maxSum;
    }

    void findMaxSum(vector<vector<int>> &M) { 
        // Variables to store the final output 
        int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom; 
        int m = M.size(), n = M[0].size();
        int left, right, start, finish, sum; 
        vector<int> tmp(n); 
        // Set the left column 
        for (left = 0; left < n; ++left) { 
            // Initialize all elements of tmp as 0 
            tmp.resize(n, 0); 
            // Set the right column for the left column set by outer loop 
            for (right = left; right < n; ++right) { 
                // Calculate sum between current left and right for every row 'i' 
                for (int i = 0; i < n; ++i) {
                    tmp[i] += M[i][right];
                }
                // Find the maximum sum subarray in tmp[]. The kadane()  
                // function also sets values of start and finish.  So 'sum' is  
                // sum of rectangle between (start, left) and (finish, right)  
                //  which is the maximum sum with boundary columns strictly as 
                //  left and right. 
                sum = kadane(tmp, start, finish, n);

                // Compare sum with maximum sum so far. If sum is more, then  
                // update maxSum and other output values 
                if (sum > maxSum) { 
                    maxSum = sum; 
                    finalLeft = left; 
                    finalRight = right; 
                    finalTop = start; 
                    finalBottom = finish; 
                } 
            } 
        } 
    
        // Print final values 
        printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft); 
        printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight); 
        printf("Max sum is: %d\n", maxSum); 
    } 
};

