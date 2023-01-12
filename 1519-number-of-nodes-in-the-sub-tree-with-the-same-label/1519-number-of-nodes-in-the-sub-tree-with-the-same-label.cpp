class Solution {
public:
    
    void merge(vector<int>&arr1,vector<int>&arr2){
        
        for(int i=0;i<26;i++){
            arr1[i]+=arr2[i];
        }
        return;
    }
    
    vector<int>dfsHelper(int curr,int prev,vector<int>adj[],string&labels,vector<int>&ans){
        
        
        vector<int>currArr(26,0);
        
        for(int&i : adj[curr]){
            if(i!=prev){
                vector<int>temp = dfsHelper(i,curr,adj,labels,ans);
                merge(currArr,temp);
            }
        }
        
        currArr[labels[curr] - 'a']++;
        ans[curr] = currArr[labels[curr] - 'a'];
        
        return currArr;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int>adj[n];
        
        for(auto&v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int>ans(n,0);
        vector<int>temp = dfsHelper(0,-1,adj,labels,ans);
        return ans;
    }
};