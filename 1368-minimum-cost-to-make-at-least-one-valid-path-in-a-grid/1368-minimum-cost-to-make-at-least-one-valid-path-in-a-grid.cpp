class Solution {
public:
    
    bool vis[101][101];
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        memset(vis,0,sizeof vis);
        
        pair<int,int>dir[5]={{0,1},{0,-1},{1,0},{-1,0}};
        
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        pq.push({0,0,0});
        
        while(pq.size()){
            
            array<int,3>curr = pq.top();
            pq.pop();

            int cost = curr[0], x  = curr[1], y = curr[2];
            
             if (vis[x][y]) 
                 continue;
            
            vis[x][y] = 1;
           
            if (x ==  n- 1 && y == m - 1) return cost;
            
            for (int i = 0; i < 4; ++i) {
                int dx = dir[i].first,dy=dir[i].second;
                
                int nx = dx + x, ny = dy + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if (i == grid[x][y] - 1) {
                        pq.push({cost, nx, ny});
                    } else {
                        pq.push({cost + 1, nx, ny});
                    }
                }
            }
        }
        
        return -1;
    }
};