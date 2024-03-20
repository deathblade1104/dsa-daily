class Solution {
public:
    int sz;
    string s;
    vector<int>dig;
    int dp[10][2][2];
    
    int helper(int currIdx,bool tight, bool hasStarted){
        
        if(currIdx>=sz){
            return hasStarted == 1;
        }
        
        int&ans = dp[currIdx][tight][hasStarted];
          
        if(ans!=-1)
            return ans;
        
        ans = 0;
        
       
        if(!hasStarted)
            ans+=helper(currIdx+1,false,false);
        
        int upper = tight ? s[currIdx] - '0' : 9;
        
        for(int&i : dig){
            
            if(i>upper)
                break;
            
            ans+=helper(currIdx+1,tight&(upper == i),true);
        }
        
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        s = to_string(n);
        sz = s.size();
        
        memset(dp,-1,sizeof dp);
        dig.clear();
        
        for(string&s : digits)
            dig.push_back(stoi(s));
    
        sort(dig.begin(),dig.end());
        
        return helper(0,1,0);
        
        
        
    }
};