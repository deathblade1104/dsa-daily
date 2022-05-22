class Solution {
public:
    
    string helper(string &s , int &curr)
    {
        string ans = "";
        while(curr<s.size() and s[curr]!=']')
        {
            
            if(isalpha(s[curr]))
                ans+=s[curr++];
            
            else
            {
                int n = 0;
                
                while(isdigit(s[curr]))
                {
                    n*=10;
                    n+=s[curr]-'0';
                    curr++;
                }
                
                
                curr++;
                string res  = helper(s,curr);
                curr++;
                
                while(n--)
                    ans+=res;
            }
        }
        
        return ans;
        
    }
    
    string decodeString(string s) {
        int curr = 0;
        return helper(s,curr);
    }
};