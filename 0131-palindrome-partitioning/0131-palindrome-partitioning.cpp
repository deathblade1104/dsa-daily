class Solution {
public:
    
    int palinDP[17][17];
    
    int isPalinHelper(int i,int j, string &s){
        
        if(i==j)
            return palinDP[i][j] = true;
        if(i == j-1)
            return palinDP[i][j] = (s[i]==s[j])? true : false;
        
        if(palinDP[i][j]!=-1)
            return palinDP[i][j];
        
        bool ans = false;
        
        if(s[i] == s[j])
            ans = true & isPalinHelper(i+1,j-1,s);
        
        bool x = isPalinHelper(i+1,j,s) , y = isPalinHelper(i,j-1,s);
        
        return palinDP[i][j] = ans;
    }
    
    void helper(int curr,string&s,vector<string>&temp,vector<vector<string>>&ans){
        
        
        if(curr>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=curr;i<s.size();i++){

            if(palinDP[curr][i]){
                temp.push_back(s.substr(curr,i-curr+1));
                helper(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
        
        return;
        
    }
    
    vector<vector<string>> partition(string s) {
        
        memset(palinDP,-1,sizeof palinDP);
        
        int x = isPalinHelper(0,(int)s.size()-1,s);
        
        vector<vector<string>>ans;
        vector<string>temp;
        
        helper(0,s,temp,ans);
        
        return ans;
    }
};