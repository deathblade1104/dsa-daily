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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        int ans=0;
    
        while(q.size()>0)
        {
            int sum=0,sz=q.size();
            while(sz--)
            {
                auto p = q.front();q.pop();
                
                sum+=p->val;
                
                if(p->left)
                    q.push(p->left);
                
                if(p->right)
                    q.push(p->right);    
            }
            
            ans=sum;
        }
        
        return ans;
    }
};