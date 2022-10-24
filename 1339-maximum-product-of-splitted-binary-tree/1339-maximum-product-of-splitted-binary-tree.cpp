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
    const long long int mod = 1e9 + 7;
    
    long long int getSum(TreeNode *root){
        
        if(!root)
            return 0LL;
        
        return (root->val)*1LL + getSum(root->left) + getSum(root->right);
    }
    
    long long int dfsHelper(TreeNode *root, long long int&treeSum, long long int&ans){
        
        if(!root)
            return 0;
        
        long long int l = dfsHelper(root->left,treeSum,ans),
        r = dfsHelper(root->right,treeSum,ans),
        currSum = (root->val*1LL) + l + r,
        currAns = (treeSum - currSum) * currSum * 1LL;
        
        ans = max(ans,currAns);
        
        return currSum;
        
    }
    int maxProduct(TreeNode* root) {
        long long int treeSum = getSum(root),ans=0LL,temp= dfsHelper(root,treeSum,ans);
        return (int)(ans%mod);
    }
};