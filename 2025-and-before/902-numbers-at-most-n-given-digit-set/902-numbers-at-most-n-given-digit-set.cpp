class Solution {
public:
    
    int dp[10][2][2];
    unordered_set<int>st;
    int low = 9, high = 0;
    
    int helper(int pos,bool tight,bool leadingZeroes,string&s){
        
        if(pos>=s.size())
            return leadingZeroes;
            
        if(dp[pos][tight][leadingZeroes]!=-1)
            return dp[pos][tight][leadingZeroes];
        
        
        int res = 0;
        int ub = tight ? s[pos]-'0' : high;
        int lb = leadingZeroes ? low : 0;
        
        for(int i=lb;i<=ub;i++){
            if(st.count(i))
                res+=helper(pos+1,tight&&(i==ub),leadingZeroes||(i>0),s); 
            
        }
        
        return dp[pos][tight][leadingZeroes] = res;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof dp);
        string s= to_string(n);
        
        st.insert(0);
        low = stoi(digits.front());
        high = stoi(digits.back());
        
        for(string&str : digits){
            int curr = stoi(str);
            st.insert(curr);
        }
        
        return helper(0,true,false,s);
        
    }
};