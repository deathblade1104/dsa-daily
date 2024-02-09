/**
 * @param {Function} fn
 * @return {Function}
 */

function memoize(fn) {
    const mp = {};
    
    return function(...args) {
        const key = args.join('_'); // Creating a unique key for the arguments
        const val = mp[key];
        
        if (val === undefined) {
            mp[key] = fn(...args);
        }
        
        return mp[key];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */