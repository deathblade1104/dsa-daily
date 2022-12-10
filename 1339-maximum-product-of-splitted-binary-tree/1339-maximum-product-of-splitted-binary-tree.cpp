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
    const int mod = 1e9 + 07;
    int treeSum;
    long long ans;
    
    int getTreeSum(TreeNode *root){
        
        if(!root)
            return 0;
        
        return getTreeSum(root->left) + getTreeSum(root->right) + root->val;
    }
    
    int getAns(TreeNode *root){
        
        if(!root)
            return 0;
        
        
        int currSum = root->val + getAns(root->left) + getAns(root->right), remSum = treeSum - currSum;
        ans = max(ans,(currSum * 1LL * remSum));
        
        return currSum;
    }
    
    
    int maxProduct(TreeNode* root) {
        
        ans = 0LL;
        treeSum = getTreeSum(root);
        
        int temp = getAns(root);
        
        return (int)(ans%mod);
    }
};