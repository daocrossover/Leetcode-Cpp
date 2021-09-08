// If 99% of all integer numbers from the stream are in the range [0, 100], 
// how would you optimize your solution?

// Assume the result will be in the [0, 100]
// Based on the follow-up 1, add a variable to record the number of elements which is less than 0

class MedianFinder {
private:
    int buckets[101];
    int n, less_than_0;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        n = 0;
        less_than_0 = 0;
    }
    
    void addNum(int num) {
        if (num < 0) {
            less_than_0++;
        } else if (num >= 0 && num <= 100) {
            buckets[num]++;
        }
        n++;
    }
    
    double findMedian() {
        // find n/2+1 th number or n/2 and n/2+1 th numbers
        int count = less_than_0, right = 0;
        for (; right < 100; right++) {
            count += buckets[right];
            if (count >= n / 2 + 1) {
                break;
            }
        }
        // if n is odd, return the n/2+1 th number directly
        if ((n & 1) == 1) {
            return right;
        }
        // find the n/2 th number
        int left = 0;
        if (buckets[right] == 1) {
            left = right - 1;
            while (buckets[left] == 0) {
                left--;
            }
        } else {
            left = right;
        }
        return (double)(left + right) / 2.0;
    }
};