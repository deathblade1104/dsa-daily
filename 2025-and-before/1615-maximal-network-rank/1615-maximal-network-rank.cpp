class Solution {
    
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size()==0) return 0;
        
        vector<unordered_set<int>>adj(n);
        for(auto &p:roads){
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        } 
        
        
        
        int ans=INT_MIN;        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                
                int temp = adj[i].size() + adj[j].size();                
                if(adj[i].count(j)==1)
                    temp--;
                
                ans=max(ans,temp);
            }
        }
        
        return ans;
        

        
    }
};