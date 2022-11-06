class Solution {
public:
    
    long long dp[101][10001];
    
    long long helper(int robotCurr, int factIdx,vector<int>&robot,vector<int>&v){
        
        if(robotCurr>=robot.size())
            return 0LL;
        
        if(factIdx>=v.size())
            return (1e18*1LL);
        
        if(dp[robotCurr][factIdx]!=-1)
            return dp[robotCurr][factIdx];
        
        
        long long op1 , op2;
        op1 = helper(robotCurr+1,factIdx+1,robot,v) + (abs(robot[robotCurr] - v[factIdx])* 1LL);
                                                       
        op2 = helper(robotCurr,factIdx+1,robot,v);
        
        return dp[robotCurr][factIdx] = min(op1,op2);
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>v;
        for (auto i:factory) {
            int x=i[0],y=i[1];
            for (int i=0;i<y;i++) {
                v.push_back(x);
            }
        }
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,robot,v);
        
        
    }
};