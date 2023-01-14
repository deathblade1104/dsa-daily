class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>&nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        array<int,2>dp[n];
        
        int ans=0,res = -1;
        
        for(int i=0;i<n;i++){
            
            dp[i]= {1,i};
            
            for(int j=0;j<i;j++){
                
                if(nums[i]%nums[j] == 0){
                    
                    if(1 + dp[j][0]>dp[i][0]){
                        dp[i][0] = 1 + dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            //cout<<i<<" : "<<dp[i][0]<<endl;
            
            if(dp[i][0]>ans){
                ans = dp[i][0];
                res = i;
            }
        }
        
        vector<int>a;
        
        while(dp[res][1]!=res){
            //cout<<res<<endl;
            a.push_back(nums[res]);
            res = dp[res][1];
        }
        
        a.push_back(nums[res]);
    
        reverse(a.begin(),a.end());
        return a;
        
        
    }
};