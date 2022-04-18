class Solution {
public:
    int DFS(int i, vector<int>adj[], int &ans, string &s)
    {
        int m1,m2;
        m1=m2=0;
        
        for(int neigh : adj[i])
        {
            int curr = DFS(neigh,adj,ans,s);
            if(s[i] == s[neigh])
                continue;
            if (curr > m2) m2 = curr;
            if (m2 > m1) swap(m1, m2);
        }
        
        ans= max(ans, m2+m1+1);
        return m1+1;
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<int>adj[n];
        
        for(int i=1;i<n;i++)
        adj[parent[i]].push_back(i);
        int ans=0;
        
        int x= DFS(0,adj,ans,s);
        return ans;
        
       
    }
};