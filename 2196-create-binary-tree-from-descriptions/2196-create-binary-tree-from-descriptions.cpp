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
    
    TreeNode *getTree(int curr,unordered_map<int,array<int,2>>&mp){
        if(curr == -1)
            return NULL;
        
        TreeNode *root =  new TreeNode(curr);
        root->left = getTree(mp[curr][0],mp);
        root->right = getTree(mp[curr][1],mp);
        
        return root;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,array<int,2>>mp;
        unordered_set<int>childSet;
        int rootVal = -1;
        
        for(auto&v : descriptions){
            
            int par = v[0], child = v[1];
            childSet.insert(child);
            
            if(mp.count(par) == 0 )
                mp[par] = {-1,-1};
            
            if(mp.count(child) == 0)
                mp[child] = {-1,-1};
            
            if(v[2] == 1)
                mp[par][0] = child;
            else
                mp[par][1] = child;
        }
        
        for(auto&v : descriptions){
            
            if(childSet.count(v[0]) ==0){
                rootVal = v[0];
                break;
            }
        }
        
        return getTree(rootVal,mp);
    }
};