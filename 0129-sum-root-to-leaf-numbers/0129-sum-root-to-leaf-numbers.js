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
 * @return {number}
 */

const helper = function(root,obj){
    
    if(!root)
        return;
    
    obj.curr*=10;
    obj.curr+=root.val;

    
    if(!root.left && !root.right){
        obj.ans+=obj.curr;
    }
    
    helper(root.left,obj);
    helper(root.right,obj);
    
    obj.curr-=root.val;
    obj.curr/=10;
    return;
}
var sumNumbers = function(root) {
    
    const obj = {};
    obj.ans = 0;
    obj.curr=0;
    
    helper(root,obj);
    return obj.ans;
    
};