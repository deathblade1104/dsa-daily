/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    
    
    
    let currArr = [];
    const results = [];
    
    for(const iter of arr){
        currArr.push(iter);
        
        if(currArr.length === size){
            results.push(currArr);
            currArr = [];
        }
    }
    
    if(currArr.length)
        results.push(currArr);
    
    return results;
    
};
