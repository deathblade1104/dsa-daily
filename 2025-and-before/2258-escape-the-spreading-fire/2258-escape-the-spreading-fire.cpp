class Solution {
public:
    int m, n;
    typedef array<int, 2> arr;
    int dir[5] = {1, 0, -1, 0, 1};

    void fireBFS(vector<vector<int>>& grid) {
        queue<arr> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {

                arr curr = q.front();
                q.pop();

                int r = curr[0], c = curr[1];

                for (int j = 1; j < 5; j++) {

                    int x = dir[j - 1] + r, y = dir[j] + c;

                    if (x < 0 or x >= m or y < 0 or y >= n or grid[x][y] <= steps)
                        continue;

                    grid[x][y] = steps;
                    q.push({x, y});
                }
            }
            steps++;
        }
    }

    bool isLastCell(int x, int y) {

        return ((x == m - 1) && (y == n - 1));
    }

    bool isPossible(int mid, vector<vector<int>>& grid) {

        if (grid[0][0] <= mid)
            return false;

        int steps = mid+1;

        vector<vector<int>> vis = grid;
        queue<arr> q;
        q.push({0, 0});
        
      
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)
                    vis[i][j] = INT_MAX;

            }
        }
        vis[0][0] = 0;
        
    
        //cout<<" --------------------"<<mid<<"---------------------------- "<<endl;        
        
        
        while (!q.empty()) {

            int sz = q.size();
            while (sz--) {

                arr curr = q.front();
                q.pop();

                int r = curr[0], c = curr[1];

                for (int j = 1; j < 5; j++) {

                    int x = dir[j - 1] + r, y = dir[j] + c;

                    if (x < 0 or x >= m or y < 0 or y >= n)
                        continue;
                    
                    
                    if (isLastCell(x, y)) {
                        if (steps <= grid[m-1][n-1])
                            return true;
                        
                        else return false;
                        
                    } else {
                        
                        //cout<<" Here : "<<x<<" : "<<y<<endl;
                        //cout<<grid[x][y]<<" ---- "<<vis[x][y]<<endl;
                        
                        if ((grid[x][y]!=INT_MAX && grid[x][y] <= steps) || vis[x][y] <= steps)
                            continue;
                        
                        //cout<<" Put in Queue : "<<x<<" : "<<y<<endl;
                        vis[x][y] = steps;
                        q.push({x, y});
                        
                        // cout<<" ------------------------------------------------ "<<endl;
                        // for(int i=0;i<m;i++){
                        //     for(int j=0;j<n;j++){
                        //         cout<<vis[i][j]<<" ";
                        //     }
                        //     cout<<endl;
                        // }
                        // cout<<" ------------------------------------------------ "<<endl;
                        
                    }
                }
            }
            steps++;
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    grid[i][j] = -2;

                if (grid[i][j] == 0) {
                    grid[i][j] = INT_MAX;
                }
            }
        }

        fireBFS(grid);
        
    
        const int highest = 50001;

        int low = 0, high = highest, ans = -1;
        isPossible(4, grid);
        

        while (low <= high) {

            int mid = low + ((high - low) / 2);

            if (isPossible(mid, grid)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        if (ans == highest)
            return 1e9;

        return ans;
    }
};