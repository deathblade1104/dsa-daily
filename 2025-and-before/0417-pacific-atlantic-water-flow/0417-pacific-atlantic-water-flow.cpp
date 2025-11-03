


class Solution {
private:
    int n, m;
    int dir[5] = {1, 0, -1, 0, 1};

    void DFS(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int prev = INT_MIN) {
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || grid[r][c]<prev) {
            return;
        }

        vis[r][c] = true;

        for (int i = 1; i <=4; i++) {
            int x = r + dir[i-1], y = c + dir[i];
            DFS(x, y, grid, vis, grid[r][c]);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis1(n, vector<bool>(m, false)), vis2(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++) {
            DFS(0, i, grid, vis1);
            DFS(n - 1, i, grid, vis2);
        }

        for (int i = 0; i < n; i++) {
            DFS(i, 0, grid, vis1);
            DFS(i, m - 1, grid, vis2);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis1[i][j] and vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
