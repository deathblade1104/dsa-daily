class Solution {

public:
    //int i;
    int dp[31];
    Solution(){
        //i = 0;
        memset(dp,-1,sizeof dp);
        //cout<<"Index"<<" : ---> "<<"Nth Term Value"<<" || "<<"Answer"<<endl;
    }
    //Recursive
//     int fib(int n) {
//         if(n<=1)
//             return n;
        
//         int ans =  fib(n-1) + fib(n-2);
//         cout<<i++<<" : ---> "<<n<<" || "<<ans<<endl;
//         return ans;
//     }
    
    
        int fib(int n) {
        if(n<=1)
            return n;
            
        if(dp[n]!=-1)
            return dp[n];
            
        int ans =  fib(n-1) + fib(n-2);
       
        return dp[n] = ans;
    }
    
    
};