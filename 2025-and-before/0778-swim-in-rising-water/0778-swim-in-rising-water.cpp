class Solution {
public:
    typedef array<int,3> arr;
    struct myComp{
        
        bool operator()(const arr&a,const arr&b){
            return a[2]>b[2];
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<arr,vector<arr>,myComp>pq;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        
        vis[0][0] = grid[0][0];
        pq.push({0,0,grid[0][0]});
        array<int,5>dir = {1,0,-1,0,1};
        
        while(pq.size()>0){
            
            arr curr = pq.top();
            pq.pop();
            int currR = curr[0],currC = curr[1],currMax = curr[2];
            
            if(currR == n-1 and currC == m-1)
                return currMax;
            
            for(int i=1;i<=4;i++){
                int x = currR +dir[i-1],y = currC + dir[i];
                
                if(x>=0 && y>=0 && x<n && y<m){
                    int tempMax = max(currMax,grid[x][y]);
                    if(tempMax<vis[x][y]){
                        pq.push({x,y,tempMax});
                        vis[x][y] = tempMax;
                    }
                }
            }
        }
        
        return -1;
        
    }
};