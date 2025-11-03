class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        
        int start =0,ans=0;
        
        for(int end=0;end<s.size();end++)
        {
            mp[s[end]]++;
            
            while(mp.size()>=3)
            {
                if(mp[s[start]]==1)
                    mp.erase(s[start]);
                else
                    mp[s[start]]--;
                
                start++;
            }
            
            ans+=start;
        }
        
        return ans;
        
    }
};