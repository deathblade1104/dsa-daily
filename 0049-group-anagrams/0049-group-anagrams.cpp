class Solution {
public:
    int count[26];
    string getSortedString(string&s){
        memset(count,0,sizeof count);
        string ans ="";
        
        for(char&ch : s)
            count[ch - 'a']++;

        for(int i=0;i<26;i++){
            
            while(count[i]--)
                ans+=(char)(i+'a');
        }
        
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        
        vector<vector<string>>ans;
        
        for(string&s : strs)
            mp[getSortedString(s)].push_back(s);
        
        for(auto it:mp)
            ans.push_back(it.second);
        
        return ans;
        
    }
};