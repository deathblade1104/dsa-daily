class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>q;
        vector<int>ans,adj[n];
        vector<int>indegree(n,0);
        
        
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==0)
                q.push(i);
            
            else
            {
                for(int x : graph[i])
                    adj[x].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int x : adj[i])
                indegree[x]++;
        }
        
        
    
        while(q.size()>0)
        {
            int curr=q.front();
            q.pop();
            
            ans.push_back(curr);
            
            
            for(int x : adj[curr])
            {
                indegree[x]--;
                
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
            
        
        
        
        
        
        
    }
};