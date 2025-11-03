class Solution {
public:
    int countSubstrings(string s, string t) {
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                int x = i, y=j,miss=0;
                
                while(x<s.size() and y<t.size())
                {
                    if(s[x]!=t[y])
                        miss++;
                    
                    if(miss==1)
                        ans++;
                    
                    if(miss>=2)
                        break;
                    x++;
                    y++;
                }
            }
        }
        
        return ans;
        
    }
};