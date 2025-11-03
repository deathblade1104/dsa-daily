class Solution {
public:
    void get_ans(int curr, string&s, unordered_map<char,char>&mp, vector<string>&ans, string&temp)
    {
        if(curr>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        char x = s[curr];
        
        if(isalpha(x))
        {          
            temp+=mp[x];
            get_ans(curr+1,s,mp,ans,temp);
            temp.pop_back();
        }
                
        temp+=x;
        get_ans(curr+1,s,mp,ans,temp);
        temp.pop_back();
        
        return;
        
    }
    vector<string> letterCasePermutation(string s) {
        
        vector<string>ans;
        string temp="";
        unordered_map<char,char>mp;
        
        for(int i=65;i<91;i++)
        {
            int l = i + 32;            
            mp[(char)i] = ((char)l);
            mp[(char)l] = ((char)i);
        }
        
        get_ans(0,s,mp,ans,temp);
        return ans;
        
    }
};