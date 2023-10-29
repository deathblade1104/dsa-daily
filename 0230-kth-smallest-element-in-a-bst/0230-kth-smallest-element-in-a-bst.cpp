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
    int K;
    
    void helper(TreeNode *r, int&currK,int&ans){
        
        if(r==nullptr or currK>=K or ans!=-1)
            return;
        
        helper(r->left,currK,ans);
        currK++;
        
        if(currK == K){
            ans = r->val;
            return;
        }
        
        helper(r->right,currK,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        int currK = 0, ans = -1;
        helper(root,currK,ans);
        return ans;
    }
};