/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    const sz = nums.length;
    const arr = new Array(sz);
    let pos = 0, neg =1;

    for(let i=0;i<sz;i++){
        
        if(nums[i]>=0){
            arr[pos] = nums[i];
            pos+=2;
        }
        
        else {
            arr[neg] = nums[i];
            neg+=2;
        }
    }
    return arr;
};