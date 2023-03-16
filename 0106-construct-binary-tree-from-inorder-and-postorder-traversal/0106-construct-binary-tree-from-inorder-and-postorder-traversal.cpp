/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    unordered_map<int, int> getInorderMap(vector<int> &inorder)
    {
        unordered_map<int, int> mp;

        int j = 0;
        for (int &i: inorder)
        {
            mp[i] = j++;
        }

        return mp;
    }

    TreeNode* helper(vector<int> &postOrder, unordered_map<int, int> &mp, int &postIdx, int l, int r)
    {
        int idx = mp[postOrder[postIdx]];
        TreeNode *root = new TreeNode(postOrder[postIdx]);
        postIdx--;
        
        
        if (r > idx)
            root->right = helper(postOrder, mp, postIdx, idx + 1, r);
        
        if (l < idx)
            root->left = helper(postOrder, mp, postIdx, l, idx - 1);



        return root;
    }
    
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        unordered_map<int, int> mp = getInorderMap(inorder);
        int l = 0, r = inorder.size() - 1, postIdx = postorder.size() - 1;

        return helper(postorder, mp, postIdx, l, r);
    }
};