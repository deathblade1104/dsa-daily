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
        vector<vector<int>>res;
        
        if(!root)
            return res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        bool rev = true;
        vector<int>ans;
        
        while(q.size()){
            int sz = q.size();
            
            while(sz--){
                
                TreeNode *f = q.front();
                q.pop();
                
                ans.push_back(f->val);
                
                if(f->left)
                    q.push(f->left);
                
                if(f->right)
                    q.push(f->right);
            }
            
            if(!rev)
                reverse(ans.begin(),ans.end());
            
            rev=!rev;
            
            res.push_back(ans);
            ans.clear();
        }
        
        return res;
    }
};