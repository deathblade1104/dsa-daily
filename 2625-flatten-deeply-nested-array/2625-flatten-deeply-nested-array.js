/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    
    if(n <=0 )
        return arr;
    
    const res = [];
    
    for(const iter of arr){
        
        if(Array.isArray(iter)){
            res.push(...flat(iter,n-1));
        }
        
        else res.push(iter);
    }
    
    return res; 
};