/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    
    let curr = nums[0];
    let count = 1;
    
    
    for(let i=1;i<nums.length;i++){
        
        if(curr == nums[i])
            count++;
        
        else count--;
        
        if(count == 0){
            count =1;
            curr =nums[i];
        }
    }
    
    return curr;
};