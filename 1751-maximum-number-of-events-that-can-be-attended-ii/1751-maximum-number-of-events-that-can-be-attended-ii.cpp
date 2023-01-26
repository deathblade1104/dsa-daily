class Solution {
public:
    
    vector<vector<int>>dp;
    int upperBound(int low,int high,int num,vector<vector<int>>&events){
        
        int ans = -1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(events[mid][0]>num){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid +1;
                
        }
        
        return ans;
    }
    int helper(int curr,int k,vector<vector<int>>&events,int&n){
        
        if(curr>=n or k<=0)
            return 0;
        
        if(dp[curr][k]!=-1)
            return dp[curr][k];
        
        int select = events[curr][2];
        int next = upperBound(curr+1,n-1,events[curr][1],events);
        
        if(next!=-1)
            next = helper(next,k-1,events,n);
        else
            next = 0;
        
        select+=next;
        
        //cout<<curr<<" NEXT "<<next<<endl;
        
        int dontSelect = helper(curr+1,k,events,n);
        
        //cout<<curr<<" SELECT "<<select<<" DONT_SELECT "<<dontSelect<<endl;
        
        return dp[curr][k] = max(select,dontSelect);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(),events.end());
        int n= events.size();
        dp  = vector<vector<int>>(n,vector<int>(k+1,-1));
        
        return helper(0,k,events,n);
        
        
        
    }
};