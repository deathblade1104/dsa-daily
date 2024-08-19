class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        int start = 0, end = 0, sz = s.size(),ans = 0,zeroes = 0,ones =0;
        
        for(;end<sz;end++){
            
            if(s[end] == '0')
                zeroes++;
            
            else ones++;
            
            
            while(ones>k and zeroes>k and start<=end){
                
                if(s[start] == '0')
                    zeroes--;
                
                else ones --;
                
                start++;
            }
            
            ans+=(end - start + 1);
        }
        
        return ans;
    }
};