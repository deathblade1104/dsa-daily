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
    int level,count;
    pair<TreeNode*,int>dummy;
    TreeNode *prev ;
    
    void getLevelAndCount(TreeNode *root,int lvl){
        
        if(!root)
            return;
        
        if(lvl == level)
            count++;
        
        else if(lvl>level){
            level = lvl;
            count = 1;
        }
        
        getLevelAndCount(root->left,lvl+1);
        getLevelAndCount(root->right,lvl+1);
        
        return;
    }
    
    pair<TreeNode *,int>getAns(TreeNode*root,int currDepth){
        
        if(!root)
            return dummy;
        
        int curr = (currDepth == level)? 1 : 0;
        
        pair<TreeNode*,int> l = getAns(root->left,currDepth+1);
        if(l.first)
            return l;
        
        curr+=l.second;
        
        pair<TreeNode*,int>r =getAns(root->right,currDepth+1);
        
        if(r.first)
            return r;
        
        curr+=r.second;
        
        pair<TreeNode*,int>res = make_pair(prev,curr);
        
        if(!l.first and !r.first and curr==count)
                res.first = root;
        
        return res;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        level = count = -1;
        prev = NULL;
        dummy = make_pair(prev,0);
        
        getLevelAndCount(root,0);
        return getAns(root,0).first;
    }
};