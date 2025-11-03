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
    unordered_map<int,int>mp2;
    unordered_map<int,set<pair<int,int>>>mp3;
    
    int DFS(TreeNode* root,int lvl){
        
        if(!root)
            return 0;
        
        mp2[root->val] = lvl; 
        
        int l = DFS(root->left,lvl+1);
        int r = DFS(root->right,lvl+1);
        
        int h = max(l,r) + 1;

        mp3[lvl].insert(make_pair(h,root->val));
        
        return h;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        int x = DFS(root,0);
        
        vector<int>ans;
        
        for(int&i : queries){
            
            int lvl = mp2[i];
            
            if(mp3[lvl].size()==1){
                ans.push_back(lvl-1);
            }
            
            
            else{
                int max_h =0;
                
                auto it = mp3[lvl].end();
                it--;
                
                if(it->second == i)
                    it --;
             
                max_h = it->first;
                ans.push_back(lvl- 1 + max_h);
            }
        }
        
        return ans;
        
        
        
    }
};