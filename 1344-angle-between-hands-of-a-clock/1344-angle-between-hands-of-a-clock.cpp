class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes;
        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};