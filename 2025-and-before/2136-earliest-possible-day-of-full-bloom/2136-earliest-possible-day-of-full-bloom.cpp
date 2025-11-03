class Solution {
public:
    
    
    
    int earliestFullBloom(vector<int>& pT, vector<int>& gT) {
         vector<pair<int,int>>v;
        
        for(int i=0;i<gT.size();i++)
            v.push_back({gT[i],pT[i]});            
        
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        int curr=0,ans=INT_MIN;
        
        for(int i=0;i<v.size();i++)
        {
            curr+=v[i].second;
            ans=max(ans,curr+v[i].first);
        }
        
        return ans;
        
    }
};