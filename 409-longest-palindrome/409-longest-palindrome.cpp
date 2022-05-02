class Solution {
public:
    int longestPalindrome(string s) {
        int mp[128];
        memset(mp,0,sizeof(mp));
        
        for(char ch  : s)
        mp[ch]++;
        
        int ans=0,odd=0;
        
        for(int i = 0;i<128;i++)
        {
            if(mp[i]&1)
            {
                odd=1;
                ans+=mp[i]-1;
            }
            
            else 
                ans+=mp[i];
            
            
        }
        
        return ans+odd;
    }
};