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
    
    
    private int sum;
    private int DFS(TreeNode root){
        
        if(root == null)
            return 0;
        
        return root.val + DFS(root.left) + DFS(root.right);
    }
    
    
    private void inOrder(TreeNode root){
        
        if(root == null)
            return;
        
        inOrder(root.left);
        sum-=root.val;
        root.val+=sum;
        inOrder(root.right);
    }

    public TreeNode bstToGst(TreeNode root) {
        sum = DFS(root);
        inOrder(root);
        
        return root;
        
    }
}