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
    
    private ArrayList<Integer>inOrder;
    
    private void getInOrder(TreeNode root){
        
        if(root == null)
            return;
        
        getInOrder(root.left);
        this.inOrder.add(root.val);
        getInOrder(root.right);
        
        return;
    }
    
    private TreeNode createBST(int l, int h){
        
        if(l>h)
            return null;
        
        int mid = l + ((h - l)/2);
        
        TreeNode root = new TreeNode(this.inOrder.get(mid));
        root.left = createBST(l,mid-1);
        root.right = createBST(mid+1,h);
        
        return root;
        
    }
    public TreeNode balanceBST(TreeNode root) {
        
        this.inOrder = new ArrayList<>();
        getInOrder(root);
        int l= 0, h = inOrder.size() -1;
        return this.createBST(0,h);
        
    }
}