class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        
        for(char&ch : s){
            
            
            if(ans.size() and ans.back() == ch)
                ans.pop_back();
            
            else
                ans+=ch;
        }
        
        return ans;
    }
};