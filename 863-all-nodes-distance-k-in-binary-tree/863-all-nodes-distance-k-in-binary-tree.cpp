/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void populateParent(TreeNode* root, TreeNode*par, unordered_map<TreeNode*,TreeNode*>&p)
    {
        if(root==NULL) return;
        p[root]=par;
        populateParent(root->left,root,p);
        populateParent(root->right,root,p);
        
        return;
    }
    
    void findKDist(TreeNode* root, int k, unordered_map<TreeNode*,TreeNode*>&p, unordered_set<TreeNode*>visited, vector<int>&ans)
    {
        if(root==NULL or k<0 or visited.find(root)!=visited.end())
        return;
        
        visited.insert(root);
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        
        findKDist(root->left,k-1,p,visited,ans);
        findKDist(root->right,k-1,p,visited,ans);
        findKDist(p[root],k-1,p,visited,ans);
        
        return;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>p;
        unordered_set<TreeNode*>visited;
        vector<int>ans;
        
        populateParent(root,NULL,p);
        findKDist(target,k,p,visited,ans);

        return ans;
        
    }
};