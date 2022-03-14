class Solution {
public:
    string simplifyPath(string path) {
        char x='/';
        path+=x;
        vector<string>st;
        string temp="";
        for(char  c : path)
        {
            if(c==x)
            {
                string a=temp;
                temp="";
                
                if(a == "" or a== ".")
                    continue;
                
                else if (a == "..")
                {
                    if(st.size()>0)
                        st.pop_back();
                    
                    continue;
                }
                
                else
                {
                    st.push_back(a);
                    continue;
                }
                
            }
            
            else
                temp+=c;
        }
        
        string ans="";
        
        if(st.size()!=0)
        for(string a : st)
            ans+="/"+a;
        
        if(ans.size()==0)
            return "/";
        
        return ans;
        
        
    }
};