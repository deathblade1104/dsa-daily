class Solution {
public:
    int DFS(int i, vector<int>adj[], int &ans, string &s)
    {
        if(adj[i].size()==0)
            return 1;
        
        int m1=0,m2=0;
            
        for(int n : adj[i])
        {
            int x = DFS(n,adj,ans,s);
            
            if(s[n] != s[i])
            {                
                if(x>m2)
                    m2=x;
                
                if(m2>m1)
                    swap(m1,m2);
            }            
        }
        ans=max(ans,m1+m2+1);
        return m1+1;
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();                
        vector<int>adj[n];
        
        for(int i=1;i<n;i++)
        adj[parent[i]].push_back(i);
        
        int ans=1;        
        int x= DFS(0,adj,ans,s);
        return ans;
        
       
    }
};