class Solution {
public:
    
    vector<vector<string>>ans;
    bool isPalindrome(string&s){
        
        int i=0,j=s.size()-1;
        
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
            
            string t = s.substr(curr,i-curr+1);
            
            if(isPalindrome(t)){
                temp.push_back(t);
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