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
    
    bool dfs(TreeNode *root,vector<int>&voyage,vector<int>&ans,int&i){
        
        if(!root)
            return true;
        
        if(root -> val!= voyage[i++])
            return false;
        // if left node exists and doesn't match voyage
        if(root -> left && root -> left -> val != voyage[i]){
            // if right node exists and matches voyage v[i], flip the node, push into vector and continue
            if(root -> right && root -> right -> val == voyage[i]) 
                ans.push_back(root -> val), swap(root -> left, root -> right);            
        
        else return false;        
        }
        return dfs(root->left,voyage,ans,i) && dfs(root->right,voyage,ans,i);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        vector<int>ans;
        int i=0;
        
        if(!dfs(root,voyage,ans,i)){
            ans.clear();
            ans.push_back(-1);
        }
        
        return ans;
        
    }
};