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
    
    unordered_map<int,int>getInorderMap(vector<int>&inorder){
        
        unordered_map<int,int>mp;
        
        int j=0;
        for(int&i : inorder){
            mp[i]= j++;
        }
        
        return mp;
    }
    
    TreeNode *helper(vector<int>&preOrder,unordered_map<int,int>&mp,int&preIdx,int l,int r){
        
        
        //cout<<"Curr Number is : "<<preOrder[pre]
        int idx = mp[preOrder[preIdx++]];
        
        
        TreeNode *root = new TreeNode(preOrder[preIdx-1]);
        
        
        if(l<idx)
            root->left = helper(preOrder,mp,preIdx,l,idx-1);
        
        if(r>idx)
            root->right = helper(preOrder,mp,preIdx,idx+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp = getInorderMap(inorder);
        int preIdx = 0, l= 0, r = inorder.size()-1;
        
        return helper(preorder,mp,preIdx,l,r);
        
    }
};