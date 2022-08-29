class Solution {
public:
    vector<int>topoSort(vector<vector<int>>&arr,int&k){
        
        vector<int>count(k+1,0);
        vector<int>adj[k+1];
        
        for(auto&x : arr){
            count[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        
        queue<int>q;
        for(int i=1;i<=k;i++)
            if(count[i]==0)
                q.push(i);
        
        vector<int>ans;
        
        while(q.size()>0){
        
            int curr = q.front();
            q.pop();
            
            ans.push_back(curr);
            
            for(int&neigh : adj[curr]){
                count[neigh]--;
                
                if(count[neigh]==0)
                    q.push(neigh);
            }
        }
        
        return ans;
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row = topoSort(rowConditions,k);
        if(row.size()<k)
            return {};
    
        vector<int>col= topoSort(colConditions,k);    
        if(col.size()<k)
            return {};
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        vector<int>idx(k+1);
        
        for(int j=0;j<col.size();j++)
            idx[col[j]]=j;
        
        for(int i=0;i<k;i++)
            ans[i][idx[row[i]]] = row[i];
        
        
        return ans;
        
            
        
    }
};