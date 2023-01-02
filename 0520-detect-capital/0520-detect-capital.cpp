#include <cctype>
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        
        int n = word.size(),small=0,large=0;
        for(int i=0;i<word.size();i++){
            
            if(islower(word[i]))
                small++;
            
            else large++;
        }
        
        if(large == n or small ==n)
            return true;
        
        if(isupper(word[0]) and large==1)
            return true;
        
        return false;
    }
};