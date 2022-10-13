class Solution {
public:
    int cost[101][101];
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i==j)
                    cost[i][j] = 0;
                
                else 
                    cost[i][j] = 9999999;
            }
        }

        for(int i=0;i<edges.size();i++){
            
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            
            cost[u][v] = w;
            cost[v][u] = w;
        }
        
        
        for(int i=0;i<n;i++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                 if(cost[src][i]!=9999999 && cost[i][dest]!=9999999)
                    cost[src][dest]=min(cost[src][dest] , cost[src][i]+cost[i][dest]);   
                }
            }
        }
        
        int res = INT_MAX, ans =-1;
        
        for(int i=0;i<n;i++){
            int curr =0;
            for(int j=0;j<n;j++){
                if(j!=i and cost[i][j]<=distanceThreshold)
                    curr++;
            }
            
            if(curr<=res){
                res = curr;
                ans=i;
            }
            
        }
        return ans;
    }
};