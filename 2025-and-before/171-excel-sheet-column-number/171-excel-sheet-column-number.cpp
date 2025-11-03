class Solution {
public:
    int titleToNumber(string ct) {
        int ans=0;
        
        for(char x:ct)
        {
            ans*=26;
            ans+=(x-'A'+1);
        }
        
        return ans;
    }
};