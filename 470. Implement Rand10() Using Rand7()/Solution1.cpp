// Description:
// Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
// Do NOT use system's Math.random().

// Example 1:
// Input: 1
// Output: [7]

// Example 2:
// Input: 2
// Output: [8,4]

// Example 3:
// Input: 3
// Output: [8,1,10]
 
// Note:
// 1. rand7 is predefined.
// 2. Each testcase has one argument: n, the number of times that rand10 is called.
 
// Follow up:
// 1. What is the expected value for the number of calls to rand7() function?
// 2. Could you minimize the number of calls to rand7()?

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

// 1. Use rand7() to generate rand49(), 
// 7 * (rand7() - 1) + (rand7() - 1) to generate rand49() - 1.
// (a - 1) * 7 + b - 1
//    1  2  3  4  5  6  7
// 1  0  1  2  3  4  5  6
// 2  7  8  9  10 11 12 13
// 3  14 15 16 17 18 19 20
// 4  21 22 23 24 25 26 27
// 5  28 29 30 31 32 33 34
// 6  35 36 37 38 39 40 41
// 7  42 43 44 45 46 47 48

// 2. resample if falls in last group (40 - 48)
// rand49() -> rand40()
// 3. rand40() -> rand10()

// Generalization
// Implement randM() using randN() when M > N:
// Step 1: Use randN() to generate randX(), where X >= M. In this problem, use 7 * (rand7() - 1) + (rand7() - 1) to generate rand49() - 1.
// Step 2: Use randX() to generate randM(). In this problem, use rand49() to generate rand40() then generate rand10.
// N^b * (randN() - 1) + N^(b - 1) * (randN() - 1) + N^(b - 2) * (randN() - 1) + ... + N^0 * (randN() - 1) generates randX() - 1, where X = N^(b + 1).

class Solution {
public:
    int rand10() {
        int result = 40;
        while (result >= 40) {
            result = 7 * (rand7() - 1) + (rand7() - 1);
        }
        return result % 10 + 1;
    }
};

// Follow up:
// E(calls) = 2*(40/49) + 4*(9/49)*(40/49) + 6*(9/49)^2*(40/49) + ...
// E(calls) = 2*(40/49) * [1 + 2*(9/49) + 3*(9/49)^2 + ...]
// Let s = 1 + 2*(9/49) + 3*(9/49)^2 + ...
// (9/49)s = (9/49) + 2*(9/49)^2 + 3*(9/49)^3 + ...
// s - (9/49)s = 1 + (9/49) + (9/49)^2 + (9/49)^3 + ...
// (40/49)s = (1 - (9/49)^n) / (1 - (9/49))
// s = (49/40)^2 * (1 - (9/49)^n)
// s = (49/40)^2 when n is infinite
// E(calls) = 2*(40/49) * (49/40)^2 = 2.45