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
    //a[0] = isBST or not
    //a[1] = maxSum yet
    //a[2] = minimum element in BST
    //a[3] = maximum element in BST
    
    array<int,4> helper(TreeNode *root, int&ans)
    {
        if(!root)
        {
            array<int,4>curr = {1,0,INT_MAX,INT_MIN};
            return curr;
        }
        
        auto l = helper(root->left,ans);
        auto r = helper(root->right,ans);
        array<int,4>curr = {0,0,INT_MAX,INT_MIN};
        
        
        if(l[0] and r[0] and root->val>l[3] and root->val<r[2])
        {
            curr[0] = 1;
            curr[1] = root->val + l[1] + r[1];
            curr[2] = min(root->val,l[2]);
            curr[3] = max(root->val,r[3]);
        }
        
        ans= max(ans,curr[1]);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        
        int ans=0;
        array<int,4> temp = helper(root,ans);
        
        return ans;
    }
};