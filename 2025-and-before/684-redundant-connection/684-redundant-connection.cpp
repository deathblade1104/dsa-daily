class Solution {
public:
    int find_par(int v, vector<int>&par)
    {
        if(v==par[v])
            return v;
        
        return par[v] = find_par(par[v],par);
    }
    
    void DS_Union(int n1, int n2, vector<int>&par, vector<int>&rank)
    {
        int p1 = find_par(n1,par) , p2 = find_par(n2,par);
        
        if(rank[p1]>=rank[p2])
        {
            rank[p1]++;
            par[p2]=p1;
        }
        
        else
        {
            par[p1]=p2;
            rank[p2]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int>par(n+1), rank(n+1,0);
        iota(par.begin(),par.end(),0);
        
        vector<int>ans;
        
        for(auto&v : edges)
        {
            int n1 = v[0] , n2= v[1];
            
            if(find_par(n1,par)==find_par(n2,par))
            return v;
            
            else
            DS_Union(n1,n2,par,rank);
        }
        
        
        return ans;
    }
};