class Solution {
public:

    struct Node {
        long long cnt;
        long long sum;

        Node(long long c = 0, long long s = 0)
            : cnt(c), sum(s) {}
    };

    string num;

    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos,
             int prev1,
             int prev2,
             bool started,
             bool tight) {

        if (pos == num.size()) {
            return Node(1, 0);
        }

        if (!tight &&
            vis[pos][prev1 + 1][prev2 + 1][started]) {
            return dp[pos][prev1 + 1][prev2 + 1][started];
        }

        int limit = tight ? num[pos] - '0' : 9;

        Node res;

        for (int d = 0; d <= limit; d++) {

            bool nextTight =
                tight && (d == limit);

            bool nextStarted =
                started || (d != 0);

            int addWave = 0;

            if (nextStarted) {

                if (started &&
                    prev1 != -1 &&
                    prev2 != -1) {

                    bool peak =
                        (prev2 < prev1 &&
                         prev1 > d);

                    bool valley =
                        (prev2 > prev1 &&
                         prev1 < d);

                    if (peak || valley)
                        addWave = 1;
                }
            }

            int nextPrev1;
            int nextPrev2;

            if (!nextStarted) {

                nextPrev1 = -1;
                nextPrev2 = -1;

            } else {

                nextPrev2 = prev1;

                if (!started)
                    nextPrev2 = -1;

                nextPrev1 = d;
            }

            Node child =
                dfs(pos + 1,
                    nextPrev1,
                    nextPrev2,
                    nextStarted,
                    nextTight);

            res.cnt += child.cnt;

            res.sum += child.sum
                     + 1LL * addWave * child.cnt;
        }

        if (!tight) {

            vis[pos][prev1 + 1][prev2 + 1][started] = true;

            dp[pos][prev1 + 1][prev2 + 1][started] = res;
        }

        return res;
    }

    long long solve(long long x) {

        if (x <= 0)
            return 0;

        num = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, -1, -1, false, true).sum;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        return solve(num2)
             - solve(num1 - 1);
    }
};