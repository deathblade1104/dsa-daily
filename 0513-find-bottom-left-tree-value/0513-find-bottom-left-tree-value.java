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
    public int findBottomLeftValue(TreeNode root) {
        
        Queue<TreeNode>q = new LinkedList<>();
        int val = root.val;
        
        q.offer(root);
        
        while(!q.isEmpty()){
            
            int sz= q.size();
            
            for(int i=0;i<sz;i++){
                
                TreeNode curr = q.poll();
                if(i == 0)
                    val = curr.val;
                
                if(curr.left!=null)
                    q.offer(curr.left);
                
                if(curr.right!=null)
                    q.offer(curr.right);
            }
        }
        
        return val;
        
    }
}