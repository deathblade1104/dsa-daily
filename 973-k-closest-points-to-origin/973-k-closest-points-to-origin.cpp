class Solution {
public:
    struct mycomp{
        bool operator()(const vector<int>&a, const vector<int>&b)
        {
            return a[0]<b[0];
        }
    };
    
    int get_distance(int&r, int&c)
    {
        int x = (r*r) + (c*c);
        return x;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>, vector<vector<int>> , mycomp>pq;
        
        for(auto i : points)
        {
            int dist= get_distance(i[0],i[1]);
            pq.push({dist,i[0],i[1]});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<vector<int>>ans;
        
        while(pq.size()>0)
        {
            auto p = pq.top(); pq.pop();
            ans.push_back({p[1],p[2]});
        }
        
        return ans;
        
        
    }
};