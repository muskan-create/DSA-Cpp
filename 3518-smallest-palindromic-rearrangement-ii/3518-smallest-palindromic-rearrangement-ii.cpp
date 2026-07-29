class Solution {
public:
    int binomCapped(int n, int r, int k) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= k) return k;
        }
        return (int)res;
    }
    
    int countMultinomialCapped(const vector<int>& freq, int k) {
        int total = 0;
        int ways = 1;
        for (int f : freq) {
            if (f == 0) continue;
            int addWays = binomCapped(total + f, f, k);
            long long tmp = (long long)ways * addWays;
            ways = (tmp >= k ? k : (int)tmp);
            total += f;
        }
        return ways;
    }
    
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> freqChar(26, 0);
        for (char c : s)
            freqChar[c - 'a']++;
        
        bool hasOdd = false;
        char mid = 0;
        vector<int> halfFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freqChar[i] % 2 != 0) {
                if (hasOdd) return "";
                hasOdd = true;
                mid = 'a' + i;
                freqChar[i]--;
            }
            halfFreq[i] = freqChar[i] / 2;
        }
        
        if (countMultinomialCapped(halfFreq, k) < k)
            return "";
        
        string half = "";
        int totalHalf = 0;
        for (int f : halfFreq)
            totalHalf += f;
        
        while ((int)half.size() < totalHalf) {
            for (int i = 0; i < 26; i++) {
                if (halfFreq[i] == 0) continue;
                halfFreq[i]--;
                int ways = countMultinomialCapped(halfFreq, k);
                if (ways >= k) {
                    half.push_back('a' + i);
                    break;
                } else {
                    k -= ways;
                    halfFreq[i]++;
                }
            }
        }
        
        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());
        return hasOdd ? half + mid + revHalf : half + revHalf;
    }
};