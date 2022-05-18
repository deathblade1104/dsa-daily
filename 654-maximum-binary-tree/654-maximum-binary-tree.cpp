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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*>st;
        
        for(int&i: nums)
        {
            TreeNode *curr = new TreeNode(i);
            
            while(st.size()>0 and st.top()->val<i)
            {
                curr->left = st.top();
                st.pop();
            }
            
            if(st.size()>0)
                st.top()->right = curr;
            
            st.push(curr);
        }
        
        while(st.size()>1)
            st.pop();
        
        return st.top();
    }
};