class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
       int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        vector<vector<bool>> seen(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>> heap;

        heap.push({dist[0][0], 0, 0});

        while (!heap.empty()) {
            auto [safe, r, c] = heap.top();
            heap.pop();

            if (seen[r][c])
                continue;

            seen[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return safe;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                    int newSafe = min(safe, dist[nr][nc]);
                    heap.push({newSafe, nr, nc});
                }
            }
        }

        return -1; 
    }
};