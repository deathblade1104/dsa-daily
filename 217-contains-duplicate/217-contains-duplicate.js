/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const st  = new Set();
    
    for (const i of nums){        
        if(st.has(i))
            {
                return true;
            }
        
        st.add(i);
    }
        return false;
    
};