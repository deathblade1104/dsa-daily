class Solution {
public:
    int colorFreq[100001][26];
    int indegree[100001];
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        memset(indegree,0,sizeof indegree);
        memset(colorFreq,0,sizeof colorFreq);
        
        int n = colors.size(), visited = 0,ans = 0;
        vector<int>adj[n];
        
        for(auto&v : edges){
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            
            if(indegree[i] == 0)
                q.push(i);
        }
        
        
        while(q.size()){
            int curr = q.front();
            q.pop();
            
            colorFreq[curr][colors[curr] - 'a']++;
            
            for(int i=0;i<26;i++)
                ans = max(ans,colorFreq[curr][i]);
            
            visited++;
           
            for(auto&neigh : adj[curr]){
                indegree[neigh]--;
                
                if(indegree[neigh] == 0)
                    q.push(neigh);
                
                for(int i=0;i<26;i++){
                    colorFreq[neigh][i]= max(colorFreq[curr][i],colorFreq[neigh][i]);
                }
            }
            
        }
        
        
        return visited == n ? ans : -1;
        
        
    }
};