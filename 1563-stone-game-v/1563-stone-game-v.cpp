class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> pre(n + 1);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                for (int k = i; k < j; k++) {
                    int L = pre[k + 1] - pre[i];
                    int R = pre[j + 1] - pre[k + 1];

                    if (L < R)
                        dp[i][j] = max(dp[i][j], L + dp[i][k]);
                    else if (L > R)
                        dp[i][j] = max(dp[i][j], R + dp[k + 1][j]);
                    else
                        dp[i][j] = max(dp[i][j],
                            max(L + dp[i][k], R + dp[k + 1][j]));
                }
            }
        }
        return dp[0][n - 1];
    }
};