class Solution {
public:
    struct mycomp{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            return a[2]>b[2];
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        vector<int>dir={1,0,-1,0,1};
        
        priority_queue<vector<int>,vector<vector<int>>,mycomp>pq;
        
        pq.push({0,0,0});
        effort[0][0]=0;
        
        while(pq.size()>0)
        {
            auto v = pq.top();
            pq.pop();
            
            int r=v[0],c=v[1],curr=v[2];
            
            if(r==n-1 and c==m-1)
            return curr;         
                         
            for(int i=1;i<=4;i++)
            {
                int x=r+dir[i-1] , y=c+dir[i];
            
                if(x>=0 and y>=0 and x<n and y<m)
                {
                    int temp = abs(heights[x][y] - heights[r][c]);
                    
                    if(temp<effort[x][y])
                    {
                        effort[x][y] = temp;
                        pq.push({x,y,max(temp,curr)});
                    }
                }
            }
          
        }
                         
        return -1;        
        
    }
};