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
    
    string ans;
    
    void updateAns(string&prev){
        
        reverse(prev.begin(),prev.end());
        
        if(this->ans == "" or prev<this->ans)
            this->ans = prev;
        
        
        reverse(prev.begin(),prev.end());
        return;
    }
    
    void DFS(TreeNode* root, string&prev){
        
        if(!root)
            return;
        
        prev+=(char)('a' + root->val);
        
        if(!root->left and !root->right){
            updateAns(prev);
        }
        
        DFS(root->left,prev);
        DFS(root->right,prev);
        
        
        prev.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        this->ans = "";
        string prev = "";
        
        DFS(root,prev);
        
        return this->ans;
        
    }
};