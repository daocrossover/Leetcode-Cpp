// 295. Find Median from Data Stream
// Description:
// The median is the middle value in an ordered integer list. 
// If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

// Implement the MedianFinder class:
// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10^-5 of the actual answer will be accepted.

// Example 1:
// Input:
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output:
// [null, null, null, 1.5, null, 2.0]

// Explanation:
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
 
// Constraints:
// 1. -10^5 <= num <= 10^5
// 2. There will be at least one element in the data structure before calling findMedian.
// 3. At most 5 * 10^4 calls will be made to addNum and findMedian.
 
// Follow up:
// 1. If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// 2. If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

// Two Heaps Solution:
// (Priority Queue in C++)
// Time Complexity: the addNum operation is O(logn), The findMedian operation is O(1).

#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> max_heap; // the smaller half of the list, max heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // the larger half of the list, min heap

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // the max_heap may only have 1 more element than the min_heap at most
        if (max_heap.empty() || num < max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        // DO NOT use max_heap.size() - min_heap.size() > 1
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        // if max_heap size = min_heap size + 1, return max_heap top
        // else max_heap size = min_heap size, return mean of max_heap top and min_heap top
        if (max_heap.size() > min_heap.size()) {
            return (double)max_heap.top();
        } else {
            return (double)(max_heap.top() + min_heap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */