class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(s.size()==0)
            return 0;
        
       else if(isPalin(s))
            return 1;
        
        return 2;       
    }
    
    bool isPalin(string &s)
    {
        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            if(s[i++]==s[j--])
                continue;
            else return false;
        }
        
        return true;
    }
};