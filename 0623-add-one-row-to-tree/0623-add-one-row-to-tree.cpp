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
    TreeNode* helper(TreeNode* root, int val, int desiredDepth, int currDepth, bool isLeft) {
        if (currDepth == desiredDepth) {
            TreeNode* newRoot = new TreeNode(val);
            if (isLeft)
                newRoot->left = root;
            else
                newRoot->right = root;
            return newRoot;
        }
        
        if (root == nullptr)
            return root;
        
        root->left = helper(root->left, val, desiredDepth, currDepth + 1, true);
        root->right = helper(root->right, val, desiredDepth, currDepth + 1, false);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        return helper(root, val, depth, 1, false);
    }
};
