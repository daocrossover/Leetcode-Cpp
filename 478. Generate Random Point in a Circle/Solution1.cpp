// 478. Generate Random Point in a Circle
// Description:
// Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

// Implement the Solution class:
// Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius and the position of the center (x_center, y_center).
// randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array [x, y].

// Example 1:
// Input
// ["Solution", "randPoint", "randPoint", "randPoint"]
// [[1.0, 0.0, 0.0], [], [], []]
// Output
// [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
// Explanation
// Solution solution = new Solution(1.0, 0.0, 0.0);
// solution.randPoint(); // return [-0.02493, -0.38077]
// solution.randPoint(); // return [0.82314, 0.38945]
// solution.randPoint(); // return [0.36572, 0.17248]

// Constraints:
// 0 < radius <= 10^8
// -10^7 <= x_center, y_center <= 10^7
// At most 3 * 10^4 calls will be made to randPoint

#include <vector>
#include <cmath>
using std::vector;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double r = radius * sqrt(random());
        double theta = random() * 2 * M_PI;
        double x = x_center + r * cos(theta);
        double y = y_center + r * sin(theta);
        return {x, y};
    }
    
private:
    double radius;
    double x_center;
    double y_center;
    
    double random() {
        return (double)rand() / RAND_MAX;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */