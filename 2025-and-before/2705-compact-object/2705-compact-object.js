/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (obj === null) return null;
    if (Array.isArray(obj)) return obj.filter(Boolean).map(compactObject);
    if (typeof obj !== "object") return obj;
    
    let resObj = {};
    
    for(const key in obj){
        
        if(!Boolean(obj[key]))
            continue;
            
        resObj = {...resObj,[key] : compactObject(obj[key])};
    };
    
    return resObj;
    
    
};