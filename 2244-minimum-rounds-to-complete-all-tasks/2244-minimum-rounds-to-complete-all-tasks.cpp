class Solution {
public:
    //int dp[100001];
    
    int minHelper(int n){
        
        if(n==0)
            return 0;
        
        else if(n==1)
            return -1;
        
        else if(n==2 or n==3)
            return 1;
        
        else if(n==4)
            return 2;
        
        else if(n%3==0)
            return n/3;
        
        return 1 + minHelper(n-3);
    }
    
    int minimumRounds(vector<int>& tasks) {
            
        // memset(dp,0,sizeof dp);
        // dp[0] = dp[1] = -1;
        // dp[2] = dp[3] = 1;
        // dp[4] = 2;
        
        unordered_map<int,int>mp;
        
        for(int&i:tasks)
            mp[i]++;
        
        int ans = 0;
        
        for(auto&it : mp){
            
            int curr = minHelper((int)it.second);
            
            //cout<<it.first<<" ---> "<<curr<<endl;
            
            if(curr == -1)
                return -1;
            
            ans+=curr;
        }
        
        return ans;
    }
};