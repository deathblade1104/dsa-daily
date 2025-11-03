class Solution {
public:
    
    bool isPalin(int i,int j, string&s){

        if(i == j)
            return true;
        
        while(i<=j){
            
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void helper(int curr,string&s, vector<string>&temp,vector<vector<string>>&ans){
        
        
        if(curr>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=curr;i<s.size();i++){
            if(isPalin(curr,i,s)){
                temp.push_back(s.substr(curr,i-curr+1));
                helper(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
        
        return;
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>temp;
        
        helper(0,s,temp,ans);
        
        return ans;
    }
};