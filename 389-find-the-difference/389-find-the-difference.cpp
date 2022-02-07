class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        
        for(auto x : s)
            mp1[x]++;
        
        for(auto x : t)
            mp2[x]++;
        
        for(auto x : t)
        {
            if(mp1.count(x)==0 or mp2[x]!=mp1[x])
                return x;
        }
        
        return '_';
        
        
        
        
       
    }
};