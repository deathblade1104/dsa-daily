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
class BSTIterator {
public:
    vector<int>ans;
    int i;
    void get_nodes(TreeNode*root)
    {
        if(!root)
            return;
        
        get_nodes(root->left);
        ans.push_back(root->val);
        get_nodes(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        i=0;
        get_nodes(root);
    }
    
    int next() {
        return ans[i++];        
    }
    
    bool hasNext() {
        return i<ans.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */