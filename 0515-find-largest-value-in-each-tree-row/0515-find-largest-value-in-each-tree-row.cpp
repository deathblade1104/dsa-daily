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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>arr;
        if(root == nullptr)
            return arr;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()){
            
            int sz = q.size();
            int maxEle = INT_MIN;
            
            while(sz--){
                TreeNode *f=q.front();
                q.pop();
                
                maxEle = max(f->val,maxEle);
                
                if(f->left!=nullptr)
                    q.push(f->left);
                
                if(f->right!=nullptr)
                    q.push(f->right);
                
            }
            arr.push_back(maxEle);
        }
        
        return arr;
    }
};