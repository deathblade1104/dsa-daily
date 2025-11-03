/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    
    const objAns = {};
    
    for(const iter of this){
        
        const key = fn(iter);

        if(!objAns.hasOwnProperty(key))
            objAns[key] =[];
        
        objAns[key].push(iter);
    }
    
    return objAns;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */