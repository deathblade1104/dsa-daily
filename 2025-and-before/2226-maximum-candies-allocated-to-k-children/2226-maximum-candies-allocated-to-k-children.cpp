class Solution {
public:
    
    bool isPossible(vector<int>&nums,int&mid,long long&k){
        
        long long sum = 0LL;
        
        for(int i : nums)
            sum+=(i/mid);
            
        return (long long)(sum/k) >0;
        
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum =0LL;
        int ele=0;
        
        for(int i : candies){
            sum+=i;
            ele = max(ele,i);
        }
        
        
        if(sum<k)
            return 0;
        
        int low=1,high = ele,ans=-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(candies,mid,k)){
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid -1 ;
            
        }
        
        return ans;
        
    }
};