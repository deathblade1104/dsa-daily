class Solution {
public:
    vector<int>par,rank;
    int findPar(int p){
        if(par[p] == p)
            return par[p];
        
        return par[p] = findPar(par[p]);
    }
    
    void DSUnion(int u,int v){
        int p1 = findPar(u), p2 = findPar(v);
        
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
        
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {        
        int n = stones.size();
        vector<array<int,2>>v;
        par.assign(n,-1);
        rank.assign(n,0);
        
        for(int i=0;i<n;i++)
            par[i] = i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    DSUnion(i,j);
            }
        }
        
        unordered_map<int,int>mp;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            mp[findPar(i)]++;
        }
        
        return n - mp.size();
    }
};