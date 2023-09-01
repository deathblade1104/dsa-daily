/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    const hashMap = {};
    const ans = [];
    for(let i=0;i<nums.length;i++){
        
        if(hashMap[target - nums[i]] != null){
            ans.push(hashMap[target - nums[i]]);
            ans.push(i);
            break;
        }
        
        hashMap[nums[i]] = i;
    }
    
    return ans;
};