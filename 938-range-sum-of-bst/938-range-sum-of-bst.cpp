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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(!root)
            return 0;
        
        int v1,v2,v3;
        v1=v2=v3=0;
        
        if(root->val>low )
            v1 = rangeSumBST(root->left,low,high);
        
        if(root->val<high)
            v2 = rangeSumBST(root->right,low,high);
        
        if(root->val>=low and root->val<=high)
            v3 = root->val;
        
        
        // cout<<root->val<<" "<<v1<<" "<<v2<<" "<<v3<<endl;
        
        return v1+v2+v3;       
        
        
    }
};