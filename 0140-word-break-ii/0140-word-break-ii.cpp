class Solution {
public:
    
    void getAns(int prev, int curr,string&s,string temp,unordered_set<string>&dict,vector<string>&ans){
        
        if(prev>=s.size()){
            ans.push_back(temp);
            ans.back().pop_back();
            
            return;
        }
        
        if(curr>=s.size())
            return;
        
        string currStr = s.substr(prev,curr - prev +1);
        
        if(dict.count(currStr)){
            string t2 = temp + currStr + " ";
            getAns(curr+1,curr+1,s,t2,dict,ans);
        }
        
        getAns(prev,curr+1,s,temp,dict,ans);
        return;
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<string>ans;
        
        getAns(0,0,s,"",dict,ans);
        
        return ans;
        
        
    }
};