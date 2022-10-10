class Solution {
public:
    string breakPalindrome(string s) {
        
        if(s.size() == 1)
            return "";
        
        int l=s.size()/2;
        
        bool non_a=true;
        
        for(int i=0;i<l;i++){
            char ch = s[i];
            
            if(ch!='a'){
                non_a = false;
                break;
            }
        }
        
        if(non_a){
            
            s.pop_back();
            s+='b';
            return s;
        }
        
        
        if(s.size() & 1)
            l++;
        
        for(int i=0;i<l;i++){
            
            if(s[i]!='a'){
                s[i]='a';
                return s;
            }
        }
        
        return s;
    }
};