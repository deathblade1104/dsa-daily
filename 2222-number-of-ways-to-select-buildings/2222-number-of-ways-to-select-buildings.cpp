class Solution {
public:
    long long numberOfWays(string s) {
        
       unordered_map<string,long long>dp;        
        for(char x : s)
        {
            if(x=='0')
            {
                dp["0"] += 1;
                dp["10"] += dp["1"];
                dp["010"] += dp["01"];
            }
            else
            {
                dp["1"] += 1;
                dp["01"] += dp["0"];
                dp["101"] += dp["10"];
            }
        }
        
        return dp["010"] + dp["101"];
        
    }
};