class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        int m=grid.size(),n=grid[0].size(),dist=0;
        vector<vector<int>>res,ans;
        int dir[5] = {0, -1, 0, 1, 0};
        
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[start[0]][start[1]]=true;
        
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int>p=q.front();
                q.pop();

                int p_r=p.first;
                int p_c=p.second;                                
                
                
                if(grid[p_r][p_c]>=pricing[0] and grid[p_r][p_c]<=pricing[1])
                    res.push_back({dist,grid[p_r][p_c],p_r,p_c});

                for (int d = 0; d < 4; ++d) {
                    
                    int x1 = p_r + dir[d], y1 = p_c + dir[d + 1];
                    if (min(x1, y1) >= 0 && x1 < grid.size() && y1 < grid[x1].size() && grid[x1][y1] != 0 
                        and vis[x1][y1]==false) {
                        
                        q.push({x1, y1});
                        vis[x1][y1]=true;
                    }
                }
             }
            dist++;
        }              
        
        
        sort(res.begin(),res.end());
        
        int i=0;
        
        while(i<res.size() and k>0)
        {
            ans.push_back({res[i][2],res[i][3]});
            i++,k--;
        }
        
        return ans;
        
    }    
    
};