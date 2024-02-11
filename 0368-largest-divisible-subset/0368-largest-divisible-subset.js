/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    nums.sort((a, b) => a - b); // Sorting the input array in ascending order
    const n = nums.length;
    const count = new Array(n).fill(1); // Array to store the size of the largest divisible subset ending at index i
    const pre = new Array(n).fill(-1); // Array to store the index of the previous element in the largest divisible subset ending at index i
    
    let maxCount = 1; // Maximum size of the divisible subset
    let maxIdx = 0; // Index of the last element of the largest divisible subset
    
    // Loop to find the largest divisible subset
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[i] % nums[j] === 0 && count[j] + 1 > count[i]) {
                count[i] = count[j] + 1;
                pre[i] = j;
                if (count[i] > maxCount) {
                    maxCount = count[i];
                    maxIdx = i;
                }
            }
        }
    }
    
    // Reconstruct the largest divisible subset
    const subset = [];
    while (maxIdx !== -1) {
        subset.push(nums[maxIdx]);
        maxIdx = pre[maxIdx];
    }
    
    return subset;
};
