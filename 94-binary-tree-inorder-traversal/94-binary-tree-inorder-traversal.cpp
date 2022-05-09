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
    
    void add_left(TreeNode *root, stack<TreeNode*>&st)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        if(!root)
            return ans;
        
        stack<TreeNode*>st;
        add_left(root,st);
        
        while(st.size()!=0)
        {
            TreeNode *curr = st.top(); st.pop();
            ans.push_back(curr->val);
            
            if(curr->right)
                add_left(curr->right,st);
        }
        
        return ans;
        
    }
};