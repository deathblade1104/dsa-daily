// var TimeLimitedCache = function() {
    
// };

// /** 
//  * @param {number} key
//  * @param {number} value
//  * @param {number} duration time until expiration in ms
//  * @return {boolean} if un-expired key already existed
//  */
// TimeLimitedCache.prototype.set = function(key, value, duration) {
    
// };

// /** 
//  * @param {number} key
//  * @return {number} value associated with key
//  */
// TimeLimitedCache.prototype.get = function(key) {
    
// };

// /** 
//  * @return {number} count of non-expired keys
//  */
// TimeLimitedCache.prototype.count = function() {
    
// };

class TimeLimitedCache {
    
    constructor(){
        this.mp = {};    
    }
    
    set(key, value, duration){
        let ans = false;
        if(this.mp.hasOwnProperty(key)){
            clearTimeout(this.mp[key].timer);
            ans = true;
        }
        
        this.mp[key] = {
            value, 
            timer: setTimeout(() => {
                delete this.mp[key];
            }, duration)
        };
        
        return ans;
    }
    
    get(key){
        return this.mp.hasOwnProperty(key) ? this.mp[key].value : -1;
    }
    
    count(){
        return Object.keys(this.mp).length;
    }
};


/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */