class Solution {
public:
    
    int res;
    vector<int>adj[(int)(1e5+1)];
    
    bool dfsHelper(int curr,int prev,vector<bool>& hasApple){
        bool ans = hasApple[curr];
        for(int&i : adj[curr]){
            if(i!=prev){
                bool checker = dfsHelper(i,curr,hasApple);
                if(checker)
                    res+=2;
                
                ans|=checker;
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        res = 0;
        for(int i=0;i<n;i++)
            adj[i].clear();
        
        for(auto&v : edges){
            int a=v[0],b=v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bool temp = dfsHelper(0,-1,hasApple);
        return res;
        
        
    }
};