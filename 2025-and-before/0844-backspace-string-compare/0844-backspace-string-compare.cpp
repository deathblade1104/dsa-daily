class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1,t1;
        s1=t1="";
        
        
        for(char&ch : s){
            if(ch == '#' and s1.size())
                s1.pop_back();
        
            if(ch!='#')
                s1+=ch;
        }
        
        for(char&ch : t){
            if(ch == '#' and t1.size())
                t1.pop_back();
        
           if(ch!='#')
                t1+=ch;
        }
        
        return s1 == t1;
    }
};