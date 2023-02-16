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
    
    
    void mapParents(TreeNode *root, TreeNode * prev,unordered_map<TreeNode*,TreeNode*>&mp){
        
        if(!root)
            return;
        
        mp[root]= prev;
        mapParents(root->left,root,mp);
        mapParents(root->right,root,mp);
        
        return;
    }
    
    TreeNode *findNode(TreeNode *root, int val){
        
        if(!root)
            return root;
        
        if(root->val == val)
            return root;
        
        TreeNode *l = findNode(root->left,val), *r = findNode(root->right,val);
        
        if(l)
            return l;
        
        if(r)
            return r;
        
        return NULL;
    }
    
    void getMaxTime(int curr,int&ans,TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp,unordered_set<int>&vis){
        
        if(!root or vis.count(root->val))
            return;
        
        ans = max(ans,curr);
        vis.insert(root->val);
        //cout<<root->val<<" : --> "<<endl;
        getMaxTime(curr+1,ans,mp[root],mp,vis);
        getMaxTime(curr+1,ans,root->left,mp,vis);
        getMaxTime(curr+1,ans,root->right,mp,vis);
        
        return;
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode *prev = NULL;
        
        mapParents(root,prev,mp);
        TreeNode *startNode = findNode(root,start);
        int ans  = 0;
        unordered_set<int>vis;
        getMaxTime(0,ans,startNode,mp,vis);
        
        return ans;
    }
};