class Solution {
public:
    
    vector<vector<string>>ans;
    bool isPalindrome(int i, int j,string&s){
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    
    void helper(int curr,string&s,vector<string>&temp){
        
        
        if(curr>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=curr;i<s.size();i++){

            if(isPalindrome(curr,i,s)){
                temp.push_back(s.substr(curr,i-curr+1));
                helper(i+1,s,temp);
                temp.pop_back();
            }
        }
        
        return;
        
    }
    
    vector<vector<string>> partition(string s) {
        
        ans.clear();
        vector<string>temp;
        
        helper(0,s,temp);
        
        return ans;
    }
};