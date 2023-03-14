/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */

const helper = function(root, obj){
    
    if(!root)
        return false;
    
    let ans;
    obj.targetSum-=root.val;
    
    if(!root.left && !root.right)
        ans =  obj.targetSum == 0? true : false;
    
    
    else    
        ans = helper(root.left,obj) || helper(root.right,obj);
    
    obj.targetSum += root.val;
    
    return ans;
}
var hasPathSum = function(root, targetSum) {
    let obj = {targetSum : targetSum};
    
    return helper(root,obj);
};