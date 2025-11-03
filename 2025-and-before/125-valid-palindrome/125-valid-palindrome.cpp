class Solution {
public:
    string get_string(string&s)
    {
        string ans="";
        
        for(char ch : s)
        {
            if(isalpha(ch))
            {
                if((int)ch <97)
                {
                    int x = (int)ch + 32;
                    ans+=(char)x;
                }
                
                else
                ans+=ch;
            }
            
            else if(isdigit(ch))
                ans+=ch;
        }
        
        return ans;
    }
    bool isPalindrome(string s) {
        
        string str= get_string(s);
        int i=0,j=str.size()-1;

        while(i<=j)
        {
            if(str[i]!=str[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};