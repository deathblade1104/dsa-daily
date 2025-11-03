class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int ans = 0;
        
        while(s.size() and s.back() == ' ')
            s.pop_back();
        
        reverse(s.begin(),s.end());
    
        for(char&ch : s){
            
            if(ch == ' ')
                break;
            
            ans++;
        }
        
        return ans;
        
    }
};