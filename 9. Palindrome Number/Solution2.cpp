// Revert half of the number
// Time Complexity: O(logn), Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;
        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        // When the length is an odd number, get rid of the middle digit by revertedNumber / 10
        // For example x == 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself),
        // we can simply get rid of it.
        return x == reverse || x == reverse / 10;
    }
};