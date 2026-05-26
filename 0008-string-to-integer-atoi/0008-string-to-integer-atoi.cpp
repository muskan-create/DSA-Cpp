class Solution {
public:
    int myAtoi(string s) {
         int i = 0, n = s.length();
        long long result = 0;
        int sign = 1;

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // 2. Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Clamp to INT_MIN / INT_MAX
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;

            i++;
        }

        return sign * result;
    }
};