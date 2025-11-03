class Solution {
public:
    int dp[365];
    
    int findIdx(int curr,int diff,vector<int>&days){
        
        int h = days.size()-1, l = curr,val = days[curr] + diff -1,ans = days.size();
        
        while(l<=h){
            
            int mid = l + ((h - l)/2);
            
            if(days[mid]>val){
                ans = mid;
                h = mid - 1;
            }
            
            else l = mid + 1;
            
        }
        
        return ans;
    }
    
    int helper(int curr,vector<int>&days,vector<int>&costs){
        
        if(curr>=days.size())
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        
        int op1 = costs[0] + helper(curr+1,days,costs);
        
        int op2 = costs[1] + helper(findIdx(curr,7,days),days,costs);
        
        int op3 = costs[2] + helper(findIdx(curr,30,days),days,costs);
        
        
        return dp[curr] = min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        
        return helper(0,days,costs);
    }
};