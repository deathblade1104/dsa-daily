class Solution {
public:
   
   struct mycomp{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            return a[0]>b[0];
        }
    };
    
    int get_par(int x, vector<int>&par)
    {
        if(x == par[x])
            return x;
        
        int res = get_par(par[x],par);
        return res;
    }
    
    void DSUnion(int n1, int n2, vector<int>&par, vector<int>&rank)
    {
        int p1 = get_par(n1,par), p2=get_par(n2,par);
        
        if(p1==p2)return;
        
        
        if(rank[p1]>rank[p2])
        par[p2]=p1;
                
        else if (rank[p2] > rank [p1])
        par[p1]=p2;    
        
        else
        {
            par[p2]=p1;
            rank[p1]++;            
        }
    }
   
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int na=1,nb=1,ans=0;
        sort(edges.begin(),edges.end(),mycomp());
        vector<int>par_A(n+1,-1),par_B(n+1,-1),rank_A(n+1,1),rank_B(n+1,1); 
             
        for(int i=0;i<=n;i++)
        par_A[i]= par_B[i]=i;
        
        for(auto edg : edges)
        {
            int type= edg[0] , v1=edg[1], v2=edg[2];
            
            if(type == 3)
            {
                if(get_par(v1,par_A)== get_par(v2,par_A) and 
                   get_par(v1,par_B)== get_par(v2,par_B))
                    ans++;
                
                else
                {
                    DSUnion(v1,v2,par_A,rank_A);
                    DSUnion(v1,v2,par_B,rank_B);
                    na++;
                    nb++;
                }
            }
            
            else if (type == 2)
            {
                if(get_par(v1,par_B) == get_par(v2,par_B))
                    ans++;
                
                else
                {
                    DSUnion(v1,v2,par_B,rank_B);
                    nb++;
                }
                
            }
            
            else 
            {
                if(get_par(v1,par_A) == get_par(v2,par_A))
                    ans++;
                
                else
                {
                    DSUnion(v1,v2,par_A,rank_A);
                    na++;
                }            
            }
        }
        
        if(na!=n or nb!=n)
            return -1;
        
        return ans;
        
    }
};