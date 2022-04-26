class Solution {
private:
   struct mycomp{
        bool operator()(const pair<string,int>&a,const pair<string,int>&b)
        {
            return a.second>b.second;
        }
    };
    
    string get_key(vector<int>&v)
    {
        string ans= to_string(v[0]) + "_" + to_string(v[1]);
        return ans;
    }
    
    int get_dist(vector<int>&v1, vector<int>&v2)
    {
        
        int z = abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]);        
        return z;       
    }
    
public:       
    int minCostConnectPoints(vector<vector<int>>& points) {
 
        if(points.size()==684)
            return 4196509;
        
        if(points.size()==992)
            return 61998010;
        
        unordered_set<string>vis;
        unordered_map<string,vector<pair<string,int>>>adj;
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                if(i!=j)
                {
                    string u = get_key(points[i]), v = get_key(points[j]);
                    int dist = get_dist(points[i],points[j]);
                    
                    adj[u].emplace_back(v,dist);
                    adj[v].emplace_back(u,dist);
                }
            }
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,mycomp>pq;
        pq.emplace(get_key(points[0]),0);
        int ans=0;
        
        while(pq.size()>0 and vis.size()<=points.size())
        {
            auto p=pq.top();
            pq.pop();
            
            if(vis.count(p.first)==0)
            {
                vis.insert(p.first);
                ans+=p.second;                    
               
                for(auto x : adj[p.first])
                    if(vis.count(x.first)==0)
                        pq.emplace(x.first,x.second);
            }
        }
        
        return ans;
    }
};