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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()>0)
        {
            int sz=q.size();
            double sum=0.0;
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                sum+=((curr->val)*1.0);
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
            
            ans.push_back((sum/(sz*1.0)));
        }
        
        return ans;
    }
};