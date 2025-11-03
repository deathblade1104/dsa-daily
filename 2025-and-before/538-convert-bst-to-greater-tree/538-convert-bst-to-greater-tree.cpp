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
    int get_sum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return root->val + get_sum(root->left) + get_sum(root->right);
    }
    void DFS(TreeNode *root, int &sum)
    {
        if(!root) return;
        
        DFS(root->left, sum);
        
        int x = root->val;
        sum-=x;
        root->val+= sum;
        
        DFS(root->right,sum);
        
        return;
        
    }
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = get_sum(root);
        DFS(root, sum);        
        return root;
    }
};