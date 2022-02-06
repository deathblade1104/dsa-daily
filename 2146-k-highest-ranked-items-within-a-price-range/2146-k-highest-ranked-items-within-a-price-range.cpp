class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        int m=grid.size(),n=grid[0].size(),dist=0;
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[start[0]][start[1]]=true;
        vector<vector<int>>res,ans,dir={{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        
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

                for(auto x : dir)
                {
                    if(x[0]+p_r>=0 and x[0]+p_r<m  and x[1]+p_c>=0 and x[1]+p_c<n 
                       and grid[x[0]+p_r][x[1]+p_c]!=0 and vis[x[0]+p_r][x[1]+p_c]==false)
                    {   
                        vis[x[0]+p_r][x[1]+p_c]=true;
                        q.push({x[0]+p_r,x[1]+p_c});
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