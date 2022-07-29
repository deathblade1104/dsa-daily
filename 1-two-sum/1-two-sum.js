/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let mp = new Map();
    
    for(let i=0;i<nums.length;i++)
    {
        if(target - nums[i] in mp)
            return [mp[target - nums[i]], i];
        
        mp[nums[i]]=i;
        
    }
    
};