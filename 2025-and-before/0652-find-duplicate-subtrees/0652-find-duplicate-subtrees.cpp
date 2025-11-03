/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode *root)
        {
            unordered_map<string, int> m;
            vector<TreeNode*> res;
            DFS(root, m, res);
            return res;
        }

    string DFS(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode*> &res)
    {
        if (!root) return "";
        string s = to_string(root->val) + "," + DFS(root->left, m, res) + "," + DFS(root->right, m, res);
        m[s]++;
        if (m[s] == 2) 
            res.push_back(root);
        return s;
    }
};