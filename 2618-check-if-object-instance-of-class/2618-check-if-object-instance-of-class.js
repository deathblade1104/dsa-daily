/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, fn) {
     if(obj === null || obj === undefined || typeof fn !== 'function')
        return false;
    return Object(obj) instanceof fn;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */