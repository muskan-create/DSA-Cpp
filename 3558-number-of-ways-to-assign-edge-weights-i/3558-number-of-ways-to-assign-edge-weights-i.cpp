class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b>0) {
            if (b&1) {
                ans = (ans*a) % MOD;
            }

            a = (a*a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int, int>> q; // {node, depth}
        vector<bool> vis(n + 1, false);

        q.push({1, 0});
        vis[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int neighbour : adj[node]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push({neighbour, depth + 1});
                }
            }
        }

        return (int)power(2, maxDepth - 1);
    }
};