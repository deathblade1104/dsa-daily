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
    long long widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 1;       
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        long long ans=1;        
        while(q.size()>0)
        {
            long long sz=q.size(), mn=q.front().second,l=INT_MAX,r=INT_MIN;
            for(long long i=0;i<sz;i++)
            {
                pair<TreeNode*,long long>p=q.front(); q.pop();
                TreeNode *curr=p.first;
                long long hd=p.second-mn;
                
                if(sz>1)
                {
                  l=min(l,hd);
                  r=max(r,hd);                    
                }
                
                if(curr->left)
                    q.push({curr->left, (hd*2*(1LL))});
                
                if(curr->right)
                    q.push({curr->right, (hd*2*(1LL))+1});
            }
            
            ans=max(ans,r-l+1);
        }
        
        return ans;
        
    }
};