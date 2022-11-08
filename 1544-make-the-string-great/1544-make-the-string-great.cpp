class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        
        for(char&ch : s){
            
            if(ans.size()>=1 and abs((int)(ch) - (int)(ans.back())) == 32)
                    ans.pop_back();
                
            else
                ans+=ch;
        }
        
        return ans;
    }
};