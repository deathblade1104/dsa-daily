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
    TreeNode* lca(TreeNode* root, TreeNode* n1,TreeNode *n2)
    {
        if(root==NULL) return NULL;
        
        if(root==n1 or root==n2)
            return root;
        
        TreeNode *l,*r;
        
        l=lca(root->left,n1,n2);
        r=lca(root->right,n1,n2);
        
        if(!l and !r)
            return NULL;
        
        else if (l and r)
            return root;
        
        else if(l)
            return l;
        
        else return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        TreeNode *l1=NULL,*l2=NULL;
        
        while(q.size()>0)
        {
            int sz=q.size(),flag=1;
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                if(flag)
                {
                    l1=curr;
                    flag=0;
                }
                
                l2=curr;
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
        }
        
        
        return lca(root,l1,l2);
        
        
    }
};