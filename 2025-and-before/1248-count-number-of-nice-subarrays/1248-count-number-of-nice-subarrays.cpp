class Solution {
public:
    int countAtMostK(vector<int>&nums,int k){

        int curr=0,start=0,ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]&1)
                curr++;
            
            while(curr>k){
                
                if(nums[start]&1)
                    curr--;
                
                start++;
            }
            
            ans+=i - start + 1;
        }
        
        return ans;
    }
    
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return countAtMostK(nums,k) - countAtMostK(nums,k-1);
        
    }
};