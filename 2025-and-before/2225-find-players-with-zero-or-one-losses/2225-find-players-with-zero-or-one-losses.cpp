class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       
        int mp[100001];
        memset(mp,-1,sizeof(mp));
        
        int lim=-1;        
        for(auto v : matches)
        {
            if(mp[v[0]]<0)
                mp[v[0]]=0;
            
            if(mp[v[1]]<0)
                mp[v[1]]=0;
            
            mp[v[1]]+=1;
            lim=max({lim,v[0],v[1]});
        }
        
        vector<vector<int>>ans(2);
        
        for(int i=1;i<=lim;i++)
        {           
            if(mp[i]==0)
                ans[0].push_back(i);
            
            if(mp[i]==1)
                ans[1].push_back(i);            
        }
        
        return ans;
        
    }
};