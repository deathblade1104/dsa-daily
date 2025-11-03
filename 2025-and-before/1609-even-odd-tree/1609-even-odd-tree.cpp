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
    
    bool oddAndIncreasing(vector<int>&v){
        
        if(!(v[0]&1))
            return false;
        
        for(int i=1;i<v.size();i++){
            
            if(!(v[i] & 1))
                return false;
            
            if(v[i]<=v[i-1])
                return false;
        }
        
        return true;
    }
    
    bool evenAndDecreasing(vector<int>&v){
        
         if((v[0]&1))
            return false;
        
        for(int i=1;i<v.size();i++){
            
            if((v[i] & 1))
                return false;
            
            if(v[i]>=v[i-1])
                return false;
        }
        
        return true;
    }
    
    
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        
        vector<int>temp;
   
        while(q.size()){
            
            int sz = q.size();
            temp.clear();
            while(sz--){
                
                TreeNode *curr = q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                
                if(curr->left)
                    q.push(curr->left);
                
                
                if(curr->right)
                    q.push(curr->right);
            }
            
            level++;
            
            if(level&1 and !oddAndIncreasing(temp))
                return false;
            
            
            if(!(level&1) and !evenAndDecreasing(temp))
                return false;
            
          
        }
        
        
        return true;
    }
};