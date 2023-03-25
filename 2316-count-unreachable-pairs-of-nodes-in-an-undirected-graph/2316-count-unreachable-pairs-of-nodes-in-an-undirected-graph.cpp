class Solution {
public:
    
    int par[100001],rank[100001];
    
    int findPar(int p){
        
        if(par[p] == p)
            return par[p];
        
        return par[p] = findPar(par[p]);
    }
    
    void DSUnion(int v1, int v2){
        
        int p1 = findPar(v1), p2 = findPar(v2);
        
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
    
    long long countPairs(int n, vector<vector<int>>& edges) {
    
        for(int i=0;i<n;i++){
            rank[i] = 0;
            par[i] = i;
        }
        
        for(auto&v: edges){
            DSUnion(v[0],v[1]);
        }
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[findPar(i)]++;
        }
        
        vector<int>vec;
        long long sum = 0LL,count = 0LL;
        for(auto&it : mp){
            vec.push_back(it.second);
            sum+=it.second;
        }
        
        for(int&i : vec){
            sum -=i;
            count+=(1LL * i * sum);
        }
        
        return count;
        
        
        
        
        
        
    }
};