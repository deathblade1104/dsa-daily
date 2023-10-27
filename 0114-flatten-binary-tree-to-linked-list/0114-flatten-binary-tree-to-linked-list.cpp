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
    pair<TreeNode*, TreeNode*> helper(TreeNode *root)
    {
        if (root == nullptr)
            return {
                nullptr,
                nullptr
            };

        TreeNode *leftHead, *leftTail, *rightHead, *rightTail;
        tie(leftHead, leftTail) = helper(root->left);
        tie(rightHead, rightTail) = helper(root->right);

        root->left = nullptr;

        if (leftHead)
        {
            root->right = leftHead;
            leftTail->right = rightHead;
        }
        else
        {
            root->right = rightHead;
        }

        TreeNode *tail = rightTail ? rightTail : (leftTail ? leftTail : root);

        return {
            root,
            tail
        };
    }

    void flatten(TreeNode *root)
    {

        helper(root);
        return;
    }
};