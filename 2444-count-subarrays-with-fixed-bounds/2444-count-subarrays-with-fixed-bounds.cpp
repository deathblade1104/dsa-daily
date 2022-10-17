class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res =0LL;
        int start=0,minKIndex=0,maxKIndex=0;
        bool minFound = false, maxFound = false;
        
        for(int i=0;i<nums.size();i++){
            
            int curr = nums[i];
            
            if(curr<minK or curr>maxK){
                start = i+1;
                minFound = maxFound = false;
            }
            if(curr == minK){
                minFound = true;
                minKIndex = i;
            }
            
            if(curr == maxK){
                maxFound = true;
                maxKIndex = i;
            }
            
            if(maxFound and minFound)
                res+=(min(minKIndex,maxKIndex) - start + 1);
            
        }
        
        return res;
    }
};