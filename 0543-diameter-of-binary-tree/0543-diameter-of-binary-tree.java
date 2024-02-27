/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private int ans;
    
    Solution(){
        ans  = 0;
    }
    
    private int helper(TreeNode root){
        
        if(root == null)
            return 0;
        
        int l = helper(root.left);
        int r  = helper(root.right);
        
        ans = Math.max(ans,l+r+1);
        return Math.max(l,r) + 1;
    }
    
    
    
    public int diameterOfBinaryTree(TreeNode root) {
        
        if(root == null)
            return 0;
        
        helper(root);
        return ans - 1;
    }
}