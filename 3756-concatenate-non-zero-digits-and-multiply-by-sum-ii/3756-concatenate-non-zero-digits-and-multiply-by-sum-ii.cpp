class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> prefSum(n + 1);

        int nz = 0;

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');
            if (s[i] != '0') nz++;
        }

        vector<int> hash(nz + 1);
        vector<int> pw(nz + 1);

        pw[0] = 1;

        vector<int> next(n);
        vector<int> prev(n);

        int id = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                hash[id + 1] = (10LL * hash[id] + (s[i] - '0')) % MOD;
                pw[id + 1] = (10LL * pw[id]) % MOD;
                prev[i] = id++;
            } else {
                prev[i] = -1;
            }
        }

        int last = -1;
        for (int i = 0; i < n; i++) {
            if (prev[i] != -1) last = prev[i];
            prev[i] = last;
        }

        last = -1;
        id = nz - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') last = id--;
            next[i] = last;
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < (int)queries.size(); i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            int L = next[l];
            int R = prev[r];

            if (L == -1 || R == -1 || L > R) {
                ans[i] = 0;
                continue;
            }

            int sum = prefSum[r + 1] - prefSum[l];

            long long val = hash[R + 1];
            val -= 1LL * hash[L] * pw[R - L + 1] % MOD;
            if (val < 0) val += MOD;

            ans[i] = (int)(val * sum % MOD);
        }

        return ans;
    }
};