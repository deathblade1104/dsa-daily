class Solution {
public:
    int ub(vector<int>&keys,int&ele)
    {
        int l=0,h=keys.size()-1;
        
        if(ele<keys[l])
            return -1;

        if(ele>=keys[h])
            return h;
        
        int ans=0;
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            
            if(keys[mid]<=ele)
            {
                ans=mid;
                
                if(mid==keys.size()-1 or keys[mid+1]>ele)
                    break;
                
                l=mid+1;
            }
               
            else
             h=mid-1;
        }
        
        return ans;
    }
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
            int k = ub(time,i);
            
            if(k==-1)
                ans.push_back(0);
            
            else ans.push_back(val[k]);
                
        }

        return ans;
    }
};