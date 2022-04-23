class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans=0,start=0;
        int mp[256];
        memset(mp,-1,sizeof(mp));
        for(int i=0;i<s.size();i++)
        {
            char x = s[i];
            
            if(mp[x]!=-1)
            start=max(start,mp[x]+1);
            
            mp[x]=i;
            
            ans=max(ans,(i-start+1));
            
        }
        
        return ans;
        
    }
};