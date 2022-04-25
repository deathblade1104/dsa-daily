class Solution {
public:
    int ub(vector<pair<int,int>>&v,int&ele,int&n)
    {
        int l=0,h=n-1,ans=0;
        
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            
            if(v[mid].first<=ele)
            {
                ans=mid;
                
                if(mid==n-1 or v[mid+1].first>ele)
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
        int ps =0,n=v.size();
                
        for(auto& p : v)
        {
            ps+=p.second;
            p.second=ps;
        }        

        vector<int>ans;
        for(auto& i: persons)
        {
            if(i<v[0].first)
                ans.push_back(0);
            
            else if(i>=v[n-1].first)
                ans.push_back(v[n-1].second);
            
            else
            {
                int k = ub(v,i,n);
                ans.push_back(v[k].second);                
            }                  
        }

        return ans;
    }
};