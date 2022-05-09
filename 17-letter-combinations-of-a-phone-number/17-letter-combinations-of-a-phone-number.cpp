class Solution {
public:
    void get_ans(int curr, string&digits, unordered_map<char,vector<char>>&mp, string&res, vector<string>&ans)
    {
        if(curr==digits.size())
        {
            ans.push_back(res);
            return;
        }
        
        
        for(int i=0;i<mp[digits[curr]].size();i++)
        {
            res+=mp[digits[curr]][i];
            get_ans(curr+1,digits,mp,res,ans);
            res.pop_back();
        }
        
        return;
        
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,vector<char>>mp;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        
        vector<string>ans;
        string res = "";
        
        if(digits=="")
            return ans;
        
        get_ans(0,digits,mp,res,ans);
        
        return ans;
        
    }
};