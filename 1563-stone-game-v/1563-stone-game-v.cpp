class Solution {
public:
    int pref[501];
    int dp[501][501];
    
    
    int helper(int start,int end){
        
        if(start >= end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int ans = 0;
        
//         for(int curr = i;curr<j;curr++){
            
//             int lSum = 0,rSum = 0;
//             if(i == 0)
//                 lSum = pref[curr];   
//             else
//                 lSum = pref[curr] - pref[i-1];
            
//             //cout<<lSum<<endl;
//             rSum = pref[j] - pref[curr]; 
            
//             if(lSum > rSum){
//                 ans = max(ans,rSum + helper(curr+1,j,arr));
//             }
            
//             else if(lSum == rSum){
//                 ans = max(ans,lSum + max(helper(curr+1,j,arr),helper(i,curr-1,arr)));
//             }
            
//             else{
//                 ans = max(ans,lSum + helper(i,curr-1,arr));
//             }
//         }
        
        for(int i=start;i<=end;i++)
        {
            int lSum,rSum;
            if(start==0)
                lSum=pref[i];
            else
            lSum=pref[i]-pref[start-1];  // st to i
            
            rSum=pref[end]-pref[i];  // i+1 to end
            
            if(lSum>rSum)
            {
                ans=max(ans,rSum+helper(i+1,end));
            }
            else if(lSum==rSum)
            {
                ans=max(ans,lSum + max(helper(start,i),helper(i+1,end)));
            }
            else
            {
                ans=max(ans,lSum+helper(start,i));
            }
        }
        
        return dp[start][end] = ans;
        
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        
        memset(pref,0,sizeof pref);
        memset(dp,-1,sizeof dp);
        pref[0] = stoneValue[0];
        int n = stoneValue.size();

        for(int i=1;i<n;i++){            
            pref[i] = pref[i-1] + stoneValue[i];
        }
        
        return helper(0,n-1);
    }
};