class Solution {
public:
    int dp[10001][101];
    int get_ans(int floor, int eggs)
    {
        if(floor==0 and eggs>0) return dp[floor][eggs]=0;
        else if (floor==1 and eggs>0) return dp[floor][eggs]=1;
        else if(eggs==0) return dp[floor][eggs]=INT_MAX/2;    
        else if(eggs==1 and floor>0) return dp[floor][eggs]=floor;
        
        if(dp[floor][eggs]!=-1) return dp[floor][eggs];
        
        int res =INT_MAX,low=1,high=floor;
        
        while(low<=high)
        {
            int mid = (low+high)/2,left = get_ans(mid-1,eggs-1),right = get_ans(floor-mid,eggs),temp =  1 + max(left,right);
            
            if(left<right)
                low=mid+1;
            
            else
                high=mid-1;
            
            res=min(res,temp);
        }
        
        return dp[floor][eggs]=res;           
    }
    
    int superEggDrop(int eggs, int floors) {
        memset(dp,-1,10001*101*sizeof(int));
        
        return get_ans(floors,eggs);      
       
    }
};