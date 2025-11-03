class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        int low = 0, high = nums.back() - nums[0],ans = 0;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            int k = 0;
            for(int i=0;i<nums.size()-1 and k<p;i++){
                
                if(nums[i+1] - nums[i] <= mid){
                    i++;
                    k++;
                }
            }
            
            if(k>=p){
                ans = mid;
                high = mid - 1;
            }
            
            else {
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};