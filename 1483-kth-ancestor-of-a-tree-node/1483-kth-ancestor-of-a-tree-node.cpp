class TreeAncestor {
public:
    vector<vector<int>>par;
    void fill_table(int n){
        for(int i=1;i<20;i++){
            for(int node = 0; node <n; node ++){
                int curr = par[node][i-1];
                if(curr != -1) 
                    par[node][i] = par[curr][i-1];
            }
        }
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        par.resize(n,vector<int>(20,-1));
        
        for(int i=0;i<n;i++)
            par[i][0] = parent[i];
        
        fill_table(n);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 19; i >= 0; i--){ 
            int num = pow(2, i);
            if(k >= num){       
                node = par[node][i];
                k -= num;       
                if(node == -1) 
                    return -1;				
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */