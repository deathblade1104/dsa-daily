class Solution {
public:
    
    string get_sorted(string &str)
    {
        int count[26];
        memset(count,0,sizeof(count));
        
        for(char c : str)
            count[c-'a']++;
        
        string ans="";
        for(int i=0;i<26;i++)
        {
            while(count[i]>0)
            {
                ans+=(char)(i+'a');
                count[i]--;
            }
        }
        
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
    
        for(auto it : strs)
        {
            string s = get_sorted(it);
            mp[s].push_back(it);           
        }        
        
        for(auto it : mp)
        {
            vector<string>v= it.second;
            ans.push_back(v);           
        }
        
        return ans;
        
    }
};