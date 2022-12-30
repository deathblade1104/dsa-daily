class Solution {
public:
    
    void DFS(int curr,vector<int>&temp,vector<vector<int>>&ans, vector<vector<int>>&graph,int&n){
        
        
        temp.push_back(curr);
        if(curr == n-1){
            ans.push_back(temp);
        }
        
        else{
            for(int&neigh : graph[curr]){
                DFS(neigh,temp,ans,graph,n);
            }
        }
        temp.pop_back();
        return;   
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n = graph.size();
        
        
        vector<int>temp;
        
        DFS(0,temp,ans,graph,n);
        return ans;
        
        
    }
};