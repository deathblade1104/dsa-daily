class Solution {
    private:
        
    struct mycomp{
        bool operator()(const pair<int,int>&a , const pair<int,int>&b)
        {
            if(a.second!=b.second)
                return a.second>b.second;
            
            return a.first>b.first;
        }
        
    };
    
     vector<vector<pair<int,int>>>make_graph(vector<vector<int>>&times,int&n)
     {
         vector<vector<pair<int,int>>>adj(n+1);        
        for(int i=0;i<times.size();i++)
        {
            int source = times[i][0], dest=times[i][1], weight=times[i][2];
            adj[source].push_back({dest,weight});
        }
        return adj;
     }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj=make_graph(times,n);
        vector<int>cost(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        pq.push({k,0});
        
        while(pq.size()>0)
        {
            pair<int,int>p=pq.top();
            pq.pop();
            
            if(cost[p.first]==-1)
            {
                cost[p.first]=p.second;
                
                vector<pair<int,int>>neigh=adj[p.first];
                
                for(auto it : neigh)
                {
                    if(cost[it.first]==-1)
                        pq.push({it.first, it.second + p.second});
                }
            }
        }
        
        int ans=-1;
        
        for (int i=1;i<=n;i++)
        {
            if(cost[i]==-1)
                return -1;
            
            else ans=max(ans,cost[i]);            
        }
        
        return ans;
        
        
        
        
    }
};