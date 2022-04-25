class Solution {
public:
    int ub(vector<int>&keys,int ele)
    {
        int l=0,h=keys.size()-1;        
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
        map<int,int>mp;
        for(auto& f : flowers)
        {
            mp[f[0]]++;
            mp[f[1]+1]--;
        }

        int ps =0,m1 = INT_MAX,m2 = INT_MIN;
        vector<int>keys;
        for (auto&i : mp)
        {
            int x=i.first, y = i.second;  
            m1 = min(m1,x);
            m2 = max(m2,x); 
            ps+=y;
            keys.push_back(x);
            mp[x]=ps;
        }

        vector<int>ans;
        for(auto& i: persons)
        {          
            if(i < m1)
            {
                ans.push_back(0);
                continue;                
            }                
            
            int k = ub(keys,min(m2,i));   
            ans.push_back(mp[keys[k]]);
        }

        return ans;
    }
};