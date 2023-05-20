class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>adj;
        
        for(int i=0;i<equations.size();i++)
        {
            string from = equations[i][0], to = equations[i][1];
            adj[from][to] = values[i];
            adj[to][from] = (1.0/values[i]);
            
            adj[from][from] = adj[to][to] = 1.0;
        }
        
        for(auto& inter : adj)
            for(auto& src : adj[inter.first])
                for(auto& dest : adj[inter.first])
                    adj[src.first][dest.first] = adj[src.first][inter.first] * adj[inter.first][dest.first]; 
        
        
        vector<double>ans;
        
        for(auto& q : queries)
        {
            string from = q[0], to=q[1];
            
            if(adj.count(from)==0 or adj[from].count(to)==0)
                ans.push_back(-1.0);
            
            else
                ans.push_back(adj[from][to]);
        }
        
        return ans;
        
        
    }
};