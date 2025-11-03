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
    int ans;
    array<int,2>dummy;
    
    array<int,2>DFS(TreeNode *root){
        
        if(!root)
            return dummy;
        
        array<int,2> l= DFS(root->left), r =  DFS(root->right);
        int currSum = l[0] + r[0] + root->val, currNodes = 1 + l[1] + r[1], average = currSum/currNodes;
        
        if(average == root->val)
            ans++;
        
        array<int,2>res= {currSum,currNodes};
        return res;
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dummy = {0,0};
        array<int,2>temp= DFS(root);
        
        return ans;
    }
};