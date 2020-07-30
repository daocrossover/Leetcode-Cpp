// Calculate the angles separately then find the difference.

#include <cmath>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = (hour % 12) * 30 + ((double)minutes / 60) * 30; // attention!
        double minute_angle = minutes * 6;
        double diff = abs(minute_angle - hour_angle);
        return diff > 180 ? 360 - diff : diff;
    }
};