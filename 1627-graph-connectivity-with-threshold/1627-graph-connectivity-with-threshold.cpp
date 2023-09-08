
class UnionFind{
    
public : 
    
    int n;
    vector<int>par,rank;
    
    UnionFind(int n){
        this->n = n;
        
        par.resize(n);
        rank.resize(n);
        
        
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int x){
        
        if(par[x] == x)
            return par[x];
        
        return par[x]= findPar(par[x]);
    }
    
   void connect(int a,int b){
        
        if(isConnected(a,b))
            return;
       
        int p1 = findPar(a),p2 = findPar(b);

        if(rank[p1]>=rank[p2]){
           rank[p1]++;
           par[p2]= p1;
        }

        else{
           rank[p2]++;
           par[p1]= p2;
        }

        return;
    }
    
    bool isConnected(int a,int b){
        return findPar(a) == findPar(b);
    }
    
    int numberOfComponents(){
        unordered_set<int>st(par.begin(),par.end());
        
        return st.size();
    }
    
    
};

class Solution {
public:
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        
        
        UnionFind DSU(n+1);
        unordered_map<int,vector<int>>mp;
        
        for(int i=t+1;i<=n;i++){
            for(int j=t+1;j<=n;j++){
                
                if(j%i == 0)
                    mp[i].push_back(j);
            }
        }
        
        for(auto&it :mp){
            for(int i=1;i<it.second.size();i++){
                DSU.connect(it.second[i-1],it.second[i]);
            }
        }
        
        int q = queries.size();
        vector<bool>ans(q);
        
        for(int i=0;i<q;i++){
            
            ans[i] = DSU.isConnected(queries[i][0],queries[i][1]);
        }
        
        return ans;
        
        
    }
};