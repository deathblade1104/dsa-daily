/**
 * @param {number[]} nums
 * @return {void}
 */
class ArrayWrapper {
    
    constructor(nums){
        this.arr = nums;
        this.sum = this.arr.reduce((acc,curr) => acc + curr,0);    
    }
}

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    console.log(JSON.stringify(this));
    return this.sum;
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    return JSON.stringify(this.arr);
    
    
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */