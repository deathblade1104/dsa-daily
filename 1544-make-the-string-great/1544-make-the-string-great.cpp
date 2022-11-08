class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        ans+=s[0];
        
        for(int i=1;i<s.size();i++){
            
            if(ans.size()>=1 and abs((int)(s[i]) - (int)(ans.back())) == 32)
                    ans.pop_back();
                
            else
                ans+=s[i];
        }
        
        return ans;
    }
};