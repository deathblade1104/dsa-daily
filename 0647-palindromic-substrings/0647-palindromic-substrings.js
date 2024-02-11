/**
 * @param {string} s
 * @return {number}
 */
const countSubstrings = function(s) {
    
    const strArr = s.split("");
    const n = strArr.length;
    const dp = new Array(n).fill(null).map(() => new Array(n).fill(-1));

    let count = n;
    for (let i = 0; i < n; i++) {
        for (let j = i+1; j < n; j++) {
            if (helper(i, j,strArr,dp)) {
                count++;
            }
        }
    }

    return count;
        
}


const helper = (i, j, strArr,dp) => {
        if (i > j) {
            return false;
        }
        if (i === j) {
            return true;
        }
        if (dp[i][j] !== -1) {
            return dp[i][j];
        }
        if (i + 1 === j) {
            dp[i][j] = strArr[i] === strArr[j];
        } else {
            dp[i][j] = (strArr[i] === strArr[j]) && helper(i + 1, j - 1,strArr,dp);
        }
    
        helper(i+1,j,strArr,dp);
        helper(i,j-1,strArr,dp);
        return dp[i][j];
    };
