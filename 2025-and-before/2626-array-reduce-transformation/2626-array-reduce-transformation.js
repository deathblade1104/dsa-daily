/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(arr, fn, init) {
        
    return arr.reduce((init,curr) => fn(init,curr),init);
};