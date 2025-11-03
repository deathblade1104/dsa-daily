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
 * @return {boolean}
 */

const helper = function(root,obj,currNode){
    
    if(!root)
        return;
    
    obj.maxNode = Math.max(obj.maxNode,currNode);
    obj.nodeCounter++;
    
    helper(root.left,obj,currNode*2);
    helper(root.right,obj,currNode*2+1);
}

var isCompleteTree = function(root) {
    
    const obj = {maxNode : 0, nodeCounter : 0};
    helper(root,obj,1);
    
    return obj.maxNode == obj.nodeCounter;
    
};