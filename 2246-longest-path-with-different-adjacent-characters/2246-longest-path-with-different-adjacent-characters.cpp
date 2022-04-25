class Solution {
public:
    int DFS(int i, vector<int>adj[], int &ans, string &s)
    {
        if(adj[i].size()==0)
            return 1;
        
        int curr=1,m1=-1,m2=-1;
            
        for(int n : adj[i])
        {
            int x = DFS(n,adj,ans,s);
            
            if(s[n] != s[i])
            {
                curr = max(curr,x+1);
                 
                if(m1==-1)
                    m1=x;
                
                else if(m1!=-1 and m2==-1)
                    m2=x;
                
                if(m1!=-1 and m2!=-1)
                {
                    ans = max(ans, (m1+m2+1));
                    m1=max(m1,m2);
                    m2=-1;
                }
            }
            
            ans = max({ans,curr,x});
        }
        
        return curr;
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();        
        if(n==1)
            return n;
        
        vector<int>adj[n];
        
        for(int i=1;i<n;i++)
        adj[parent[i]].push_back(i);
        
        int ans=0;        
        int x= DFS(0,adj,ans,s);
        return ans;
        
       
    }
};