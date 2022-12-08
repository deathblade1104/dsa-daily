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
    
    
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>childSet;
        int rootVal = -1;
        
        for(auto&v : descriptions){
            
            int par = v[0], child = v[1];
            childSet.insert(child);
            
            if(mp.count(par) == 0 )
                mp[par] = new TreeNode(par);
            
            if(mp.count(child) == 0)
                mp[child] = new TreeNode(child);
            
            if(v[2] == 1)
                mp[par]->left = mp[child];
            else
                mp[par]->right = mp[child];
        }
        
        for(auto&v : descriptions){
            if(childSet.count(v[0]) ==0){
                rootVal = v[0];
                break;
            }
        }
        
        return mp[rootVal];
    }
};