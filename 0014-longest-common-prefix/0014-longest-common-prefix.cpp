class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        unordered_map<string,int>mp;
        
        for(string&s : strs){
            string ans = "";
            for(char&ch : s){
                ans+=ch;
                mp[ans]++;
            }
        }
        
        
        string ans = "";
        for(auto it : mp){
            string s = it.first;
            if(it.second == strs.size() and s.size()>=ans.size())
                    ans = s;
        }
        
        return ans;
    }
};