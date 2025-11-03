class Solution {
public:
    
    static const int mod = 1e9 + 7;
    
    int numberOfUniqueGoodSubsequences(string s) {
        
        int zeroes = 0, ones = 0, res = 0;
        
        for(char&ch : s){
            
            if(ch == '0'){
                zeroes = (zeroes%mod + ones%mod)%mod;
            }
            
            else ones = (1 + ones%mod + zeroes%mod)%mod;
        }
        
        int start = (zeroes>0 || s[0] == '0') ? 1 : 0;
        
        res = (ones%mod + zeroes%mod + start)%mod;
        return res;
    }
};