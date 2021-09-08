// If all integer numbers from the stream are in the range [0, 100], 
// how would you optimize your solution?

// Count (Bucket) Sort:

class MedianFinder {
private:
    int buckets[101];
    int n;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        buckets[num]++;
        n++;
    }
    
    double findMedian() {
        // find n/2+1 th number or n/2 and n/2+1 th numbers
        int count = 0, right = 0;
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