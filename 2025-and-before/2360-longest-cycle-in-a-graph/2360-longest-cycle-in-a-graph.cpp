class Solution {
public:
    
    void DFS(int curr, vector<int>&edges,int depth,int &cycle, vector<bool>&vis,unordered_map<int,int>&anc)
    {
        if(curr==-1)
            return;
        
        if(vis[curr]){
            
            if(anc.count(curr)==1)            
            cycle = max(cycle,depth-anc[curr]);
            
            return;
        }
        
        vis[curr] = true;
        anc[curr] = depth;
        DFS(edges[curr],edges,depth+1,cycle,vis,anc);
        
        
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size(),ans = -1;
        
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            
            if(vis[i])
                continue;
            
            unordered_map<int,int>anc;
            int cycle = -1;
            
            DFS(i,edges,1,cycle,vis,anc);
            ans = max(ans,cycle);
        }
        
        return ans;
        
        
    }
};