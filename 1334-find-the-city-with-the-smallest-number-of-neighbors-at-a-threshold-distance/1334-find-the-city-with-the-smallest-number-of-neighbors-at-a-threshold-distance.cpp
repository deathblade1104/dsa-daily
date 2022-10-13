class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>costs(n,vector<int>(n));
          int minReach=101;
            int maxAns=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    costs[i][j]=0;
                else 
                    costs[i][j]=INT_MAX;
            }
        }
        
        for(auto eachEdges:edges)
        {
            int src=eachEdges[0];
            int dest=eachEdges[1];
            int weight=eachEdges[2];
          
            
            costs[src][dest]=weight;
            costs[dest][src]=weight;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int src=0;src<n;src++)
            {
                for(int dest=0;dest<n;dest++)
                    
                {
                    if(costs[src][i]!=INT_MAX && costs[i][dest]!=INT_MAX)
                    costs[src][dest]=min(costs[src][dest] , costs[src][i]+costs[i][dest]);
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
           int reach=0;
            vector<int>tempReach=costs[i];
            for(auto k:tempReach)
            {
               if(k >0 && k<=distanceThreshold)
                   reach++;
            }
            // cout<<reach<<"   <- "<<i<<endl;
            
            if(reach <= minReach)
            {
                minReach=reach;
                maxAns=i;
                
            }
            
            
        }
        
        return maxAns;
    }
};