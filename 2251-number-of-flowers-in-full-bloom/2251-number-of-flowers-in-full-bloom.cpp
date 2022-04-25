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
         map<int,int>mp;
        for(auto& f : flowers)
        {
            mp[f[0]]++;
            mp[f[1]+1]--;
        }

        int ps =0;
        vector<int>keys;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            int x=i->first, y = i->second;  
            ps+=y;
            keys.push_back(x);
            mp[x]=ps;
        }

        vector<int>ans;
        for(auto& i: persons)
        {
            int k = ub(keys,i);

            if(k==-1)
                ans.push_back(0);
            
            else 
                ans.push_back(mp[keys[k]]);
        }

        return ans;
    }
};