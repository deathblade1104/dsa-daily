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
    void attach(unordered_map<int,vector<TreeNode*>>&mp,int&lvl,TreeNode *curr)
    {   
        if(lvl!=0)
        {
            int par_lvl = lvl - 1,sz = mp[par_lvl].size()-1;

            if(mp[par_lvl][sz]->left == NULL)
                mp[par_lvl][sz]->left = curr;

            else if(mp[par_lvl][sz]->right == NULL)
                mp[par_lvl][sz]->right = curr;                        
        }
        return;
    }
    void fill_by_level(string&traversal, unordered_map<int,vector<TreeNode*>>&mp)
    {
        int lvl=0,num=0;
        for(int i=0;i<traversal.size();i++)
        {
            if(traversal[i]=='-')
            {
                if(isdigit(traversal[i-1]))
                {
                    TreeNode *curr = new TreeNode(num);
                    mp[lvl].push_back(curr);
                    attach(mp,lvl,curr);                    
                    num=0;
                    lvl=1;
                }
                
                else
                    lvl++;
            }
            
            else
            {
                num*=10;
                num+= (traversal[i]-'0');
            }
        }
        
       TreeNode *curr = new TreeNode(num);
       mp[lvl].push_back(curr);
       attach(mp,lvl,curr);
       return;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,vector<TreeNode*>>mp;        
        fill_by_level(traversal,mp);        
        return mp[0][0];        
    }
};