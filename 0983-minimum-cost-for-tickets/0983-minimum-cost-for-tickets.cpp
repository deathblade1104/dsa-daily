class Solution {
public:
    int dp[365];
    
    int findIdx(int curr,int diff,vector<int>&days){
        
        if(curr == days.size()-1)
            return curr+1;
        
        int initCurr = curr;
        while(curr<days.size() and days[curr] - days[initCurr] < diff)
            curr++;
        
        return curr;
    }
    
    int helper(int curr,vector<int>&days,vector<int>&costs){
        
        if(curr>=days.size())
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        //cout<<days[curr]<<" next -->"<<endl;
        
        int op1 = costs[0] + helper(curr+1,days,costs);
        
        int op2 = costs[1] + helper(findIdx(curr,7,days),days,costs);
        
        int op3 = costs[2] + helper(findIdx(curr,30,days),days,costs);
        
        //cout<<days[curr]<<" --> "<<op1<<" : "<<op2<<" : "<<op3<<endl;
        return dp[curr] = min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        
        return helper(0,days,costs);
    }
};