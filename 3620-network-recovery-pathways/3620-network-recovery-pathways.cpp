class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> &graph) {
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int next : graph[node]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return order;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> graph(n);

        int maxWeight = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            graph[u].push_back(v);

            maxWeight = max(maxWeight, w);
        }

        vector<int> topo = topoSort(n, graph);

        auto check = [&](int limit) {

            vector<long long> dist(n, 1e18);
            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == 1e18)
                    continue;

                for (auto &it : adj[u]) {

                    int v = it.first;
                    int w = it.second;

                    if (w < limit)
                        continue;

                    if (!online[v])
                        continue;

                    dist[v] = min(dist[v], dist[u] + w);
                }
            }

            return dist[n - 1] <= k;
        };

        if (!check(0))
            return -1;

        int low = 0;
        int high = maxWeight;

        while (low < high) {

            int mid = low + (high - low + 1) / 2;

            if (check(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};