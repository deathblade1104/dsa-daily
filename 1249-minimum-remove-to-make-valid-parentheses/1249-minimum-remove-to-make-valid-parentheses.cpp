class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ob=0,cb=0;
        string ans="";
        
        for(char x : s)
        {
            if(x=='(')
            {
                ob++;
                ans+=x;
            }
            
            else if(x==')')
            {
                cb++;
                ans+=x;
                
                if(cb>ob)
                {
                    ans.pop_back();
                    cb--;
                }
            }
            
            else
            ans+=x;
        }
        
        
        if(ob>cb)
        {
            string temp="";
            for(int i=ans.size()-1;i>=0 ;i--)
            {
                if(ans[i]!='(')
                    temp+=ans[i];
                
                else
                {
                    if(ob>cb)
                        ob--;
                    
                    else
                        temp+=ans[i];
                }
            }
            
            reverse(temp.begin(),temp.end());
            return temp; 
            
        }
        
        return ans;        
        
        
        
        
    }
};