class Solution {
public:
    
    static bool mycomp(pair<int,int>a,pair<int,int>b)
    {
        if(a.first !=b.first)
       return a.first>b.first;
        
        else 
            return a.second<b.second;
    }
    
    int earliestFullBloom(vector<int>& pT, vector<int>& gT) {
         vector<pair<int,int>>v;
        
        for(int i=0;i<gT.size();i++)
            v.push_back({gT[i],pT[i]});            
        
        
        sort(v.begin(),v.end(),mycomp);
        
        int curr=0,ans=INT_MIN;
        
        for(int i=0;i<v.size();i++)
        {
            curr+=v[i].second;
            ans=max(ans,curr+v[i].first);
        }
        
        return ans;
        
    }
};