class Solution {
private:
    int find_par(int v, vector<int>&par)
    {
        if(v == par[v])
            return v;
        
        return par[v] = find_par(par[v],par);
    }
    
    void DSUnion(int v1,int v2, vector<int>&par, vector<int>&rank)
    {
        int p1= find_par(v1,par), p2=find_par(v2,par), r1=rank[p1], r2=rank[p2];
        
        if(p1!=p2)
        {            
            if(r1>r2)
            par[p2]=p1;
            
            else if(r2>r1)
            par[p1]=p2;
            
            else
            {
                rank[p1]++;
                par[p2]=p1;
            }
            
        }
        
        return;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int>par(n+1),rank(n+1,0),ans;
        
        for(int i=1;i<=n;i++)
            par[i]=i;
        
        
        for(auto temp : edges)
        {
            int v1= temp[0],v2=temp[1];
            
            if(find_par(v1,par)==find_par(v2,par))
            {
                ans.push_back(v1);
                ans.push_back(v2);
                break;
            }
            
            else
                DSUnion(v1,v2,par,rank);
        }
        
        return ans;
        
    }
};