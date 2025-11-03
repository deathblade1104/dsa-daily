class Solution {
public:
    
    bool isValid[1001][1001];
    int n;
    int dp[1001][1001];
    
    int helper(int start,int end){
        
        if(end == n-1){
            return isValid[start][end] == true ? 1 : 2*n;
        }
            
        int&ans = dp[start][end];
    
        if(ans!=-1)
            return ans;
        
        int op1 = isValid[start][end] == true ? 1 + helper(end+1,end+1): n+n;
        int op2 = helper(start,end+1);
        
        return ans = min(op1,op2);
        
    }
    
    int minimumSubstringsInPartition(string s) {
        
        n = s.size();
        memset(isValid,0,sizeof isValid);
        memset(dp,-1,sizeof dp);
        
        for(int i=0;i<n;i++){
            vector<int>arr(26,0);
            unordered_map<int,int>mp;
            
            for(int j=i;j<n;j++){
                int idx = s[j] -'a';
                
                if(arr[idx]>0){
                    mp[arr[idx]]--;
                    
                    if(mp[arr[idx]] == 0)
                        mp.erase(arr[idx]);
                }
                
                arr[idx]++;
                mp[arr[idx]]++;
                isValid[i][j] = mp.size() == 1;
            }
        }
        
        
        return helper(0,0);
       
        
    }
};