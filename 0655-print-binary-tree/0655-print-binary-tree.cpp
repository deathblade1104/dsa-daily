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
    int getHeight(TreeNode *root){
        
        if(!root)
            return 0;
        
        return 1 + max(getHeight(root->left),getHeight(root->right));
    }
    
    void getAns(TreeNode *root, vector<vector<string>>&ans,int currRow, int left, int right){
        
        if(!root)
            return;
        
        int mid = left + ((right - left)/2);
        //cout<<currRow<<" : "<<mid<<endl;
        ans[currRow][mid] = to_string(root->val);
        
        getAns(root->left,ans,currRow+1,left,mid-1);
        getAns(root->right,ans,currRow+1,mid+1,right);
        
        return;
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int rows = getHeight(root),cols = pow(2,rows) - 1;
        vector<vector<string>>ans(rows,vector<string>(cols,""));
        getAns(root,ans,0,0,cols-1);
        return ans;    
    }
};