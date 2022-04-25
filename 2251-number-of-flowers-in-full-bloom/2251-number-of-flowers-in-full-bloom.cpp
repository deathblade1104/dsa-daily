class Solution {
public:
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        vector<pair<int,int>>v;
        for(auto& f : flowers)
        {
            v.push_back({f[0],1});
            v.push_back({f[1]+1,-1});
        }
        
        sort(v.begin(),v.end());
        int ps =0;
        vector<int>time,val;
        
        for(auto& p : v)
        {
            ps+=p.second;
            time.push_back(p.first);
            val.push_back(ps);
        }        

        vector<int>ans;
        for(auto& i: persons)
        {
            auto it = upper_bound(time.begin(), time.end(), i); 
            if (it == time.begin()) ans.push_back(0); 
            else ans.push_back(val[it - time.begin() - 1]);
                
        }

        return ans;
    }
};