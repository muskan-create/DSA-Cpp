class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
        int maxLen = 0, start = 0;

        auto isPalin = [&](int i, int j) {
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalin(i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);  
    }
};