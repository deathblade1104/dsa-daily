class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        
        string ans ="",curr="";
        
        
        for(char&ch : s){
            
            if(ch!=' ')
                curr+=ch;
            
            else{
                
                reverse(curr.begin(),curr.end());
                ans+=curr+" ";
                curr="";
            }
        }
        
        ans.pop_back();
        return ans;
        
    }
};