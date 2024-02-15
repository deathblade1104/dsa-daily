/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
        
    const res = [];
    
    for(const iter of arr){
        
        if(Array.isArray(iter) && n>0){
            res.push(...flat(iter,n-1));
        }
        
        else res.push(iter);
    }
    
    return res; 
};