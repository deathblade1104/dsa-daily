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
    void getLeaves(TreeNode *root, vector<int>&ans){
        
        if(!root)
            return;
        
        getLeaves(root->left,ans);
        if(!root->left and !root->right){
            ans.push_back(root->val);
            return;
        }
        getLeaves(root->right,ans);
        
        return;
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        
        getLeaves(root1,ans1);
        getLeaves(root2,ans2);
        
        if(ans1.size() == ans2.size()){
            int i=0;
            
            while(i<ans1.size()){
                
                if(ans1[i] != ans2[i])
                    return false;
                i++;
            }
            
            return true;
        }
        
        return false;
    }
};