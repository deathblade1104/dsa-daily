/**
 * @param {number} n
 * @return {number}
 */

const helper = (n, dp) => {
    
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 1;
    
    if(dp[n])
        return dp[n];
    
    
    let ans = Infinity;
    for(let i=1;i*i<=n;i++){
        
        let curr = 1 + helper(n - i*i,dp);
        ans = Math.min(ans,curr);
    }
    
    return dp[n] = ans;
};

const  numSquares = function(n) {
    
    const dp ={};
    return helper(n,dp);
    
};