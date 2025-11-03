class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", s2="";
        
        for(char ch : s)
        {
            if(ch == '#' and s1.size()>0)
                s1.pop_back();
            
            if(ch!='#')
            s1+=ch;
        }
        
        for(char ch : t)
        {
            if(ch == '#' and s2.size()>0)
                s2.pop_back();
            
            if(ch!='#')
                s2+=ch;
        }
        
        return (s1==s2);
    }
};