class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n; // remaining amount of numbers
        int step = 1;
        int head = 1; // left number
        while (remaining > 1) {
            if (left || remaining % 2 == 1) {
                // odd amount or left-to-right order
                head = head + step;
            }
            remaining = remaining / 2;
            step = step * 2;
            left = !left;
        }
        return head;
    }
};