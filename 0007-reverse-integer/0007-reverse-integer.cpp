class Solution {
public:
    int reverse(int x) {
       return helper(x, 0);
    }

    int helper(int x, int rev) {
        if (x == 0) return rev;
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;

        int rem = x % 10;
        x = x / 10;
        rev = rev * 10 + rem;

        return helper(x, rev); 
    }
};