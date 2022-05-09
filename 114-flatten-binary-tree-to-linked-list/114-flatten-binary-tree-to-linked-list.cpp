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
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
        stack<TreeNode*>st;
        st.push(root);
                       
        while(st.size()>0)
        {
            TreeNode *curr= st.top(); st.pop();
            
            if(curr->right)
                st.push(curr->right);
            
            if(curr->left)
                st.push(curr->left);
            
            curr->left = NULL;
            
            if(st.size()!=0)
                curr->right = st.top();
            else
                curr->right = NULL;
        }
        
        
    }
};