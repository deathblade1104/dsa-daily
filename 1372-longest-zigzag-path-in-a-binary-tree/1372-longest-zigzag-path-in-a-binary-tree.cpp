/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    array<int,3> DFS(TreeNode *root)
    {
        if(!root)
            return {-1,-1,0};
        
        
        array<int,3> l = DFS(root->left);
        array<int,3> r = DFS(root->right);
        
        array<int,3>ans={0,0,0};
        
        int consider_root = max(l[1],r[0]) + 1;
        ans[2] = max({consider_root,l[2],r[2]});
        
        ans[0] = l[1] + 1;
        ans[1] = r[0] + 1;
        
        return ans;     
        
    }
    
    int longestZigZag(TreeNode* root) {
        
        return DFS(root)[2];
        
    }
};