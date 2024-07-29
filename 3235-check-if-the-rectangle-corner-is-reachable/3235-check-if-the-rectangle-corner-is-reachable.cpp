class DSU{
private: 
    int n;
    vector<int>par,rank;
public:
    
    DSU(int n){
        
        this->n = n;
        par.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int p){
        
        if(par[p] == p)
            return par[p];
        
        return findPar(par[p]);
    }
    
    void unionNodes(int u, int v){
        
        int p1 = findPar(u),p2 = findPar(v);
        
        if(p1 == p2)
            return;
        
        if(rank[p1]>=rank[p2]){
            rank[p1]++;
            par[p2] = p1;
        }
        
        else{
            rank[p2]++;
            par[p1] = p2;
        }
    }
};

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        
        int n=circles.size();
        DSU dsu(n+5);
        int i=0;
        for(auto it:circles){
            int xi=it[0],yi=it[1],ri=it[2];
            if(xi<=ri){
                dsu.unionNodes(i,n+3);
            }
            if(yi<=ri){
                dsu.unionNodes(i,n);
            }
            if(X-xi<=ri){
                dsu.unionNodes(i,n+1);
            }
            if(Y-yi<=ri){
                dsu.unionNodes(i,n+2);
            }
            i++;
        }
        i=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=circles[i][0];
                int y1=circles[i][1];
                int r1=circles[i][2];
                int x2=circles[j][0];
                int y2=circles[j][1];
                int r2=circles[j][2];
                double dist=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
                if(dist<=(r1+r2)){
                    dsu.unionNodes(i,j);
                }
            }
        }
        if(dsu.findPar(n+3)==dsu.findPar(n+1)|| dsu.findPar(n+3)==dsu.findPar(n)){
            return false;
        }
        if(dsu.findPar(n+2)==dsu.findPar(n+1) || dsu.findPar(n+2)==dsu.findPar(n)){
            return false;
        }
        return true;
        
    }
};