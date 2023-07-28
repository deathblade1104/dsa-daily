class Solution {
int dp[21][21]; //dp array
	//dp[i][j]= maxm a player can score if they have access to elements form index i to index j only
    bool checkWin(int ans,int total){
        return ans>=total-ans;
    }
    int maxScore(vector<int>&A,int total,int i,int j){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=total-min(maxScore(A,total-A[i],i+1,j),maxScore(A,total-A[j],i,j-1));
        return dp[i][j];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int total=0;
        for(int i=0;i<21;i++)
            for(int j=0;j<21;j++)
                dp[i][j]=-1;  //initialising to -1
        for(auto x:nums)
            total+=x;
        return checkWin(maxScore(nums,total,0,nums.size()-1),total);
    }
};