class Solution {
public:
    
    bool isPossible(int&mid,vector<int>&arr,int&cap){
        
        int currSum = 0;
        for(int&i : arr){
            currSum +=i/mid;
            
            if(i%mid)
                currSum++;
            
            if(currSum>cap)
                return false;
        }
        
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = INT_MAX,ans = -1 ;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(mid,nums,threshold)){
                ans = mid;
                high = mid -1;
            }
            
            else low = mid +1;
        }
        
        return ans;
    }
};