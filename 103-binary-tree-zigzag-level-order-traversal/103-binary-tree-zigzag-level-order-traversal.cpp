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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;        
        if(!root)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(q.size()>0)
        {
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++)
            {
                TreeNode *t = q.front();
                q.pop();
                
                temp.push_back(t->val);
                
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }
            
            if(!flag)
                reverse(temp.begin(),temp.end());
            
            flag=!flag;
            ans.push_back(temp);
        }
        
        return ans;
    }
};