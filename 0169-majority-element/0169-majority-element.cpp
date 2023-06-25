class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=1,currNum = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            if(currNum != nums[i]){
                count--;
            }
            else
                count++;
            
            if(count == 0){
                count = 1;
                currNum = nums[i];
            }
        }
        
        return currNum;
    }
};