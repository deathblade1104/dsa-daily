class Solution {
public:
    string get_sorted_string(string &str)
    {
        vector<int>arr(26,0);
        string ans="";
        for(char ch : str)
            arr[ch - 'a']++;
               
        for(int i=0;i<26;i++)
        {
            while(arr[i]--)
                ans+= (char)(i + 'a');
        }
        
        return ans;
        
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;
        
        for(auto&str : strs)
        {
            string ans = get_sorted_string(str);
            
            mp[ans].push_back(str);
        }
        
        for(auto itr : mp)
            ans.push_back(itr.second);
        
        
        return ans;
        
    }
};