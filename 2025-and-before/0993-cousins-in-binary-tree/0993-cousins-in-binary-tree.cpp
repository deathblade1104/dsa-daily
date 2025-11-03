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
        bool isCousins(TreeNode *root, int x, int y)
        {
            queue<pair<TreeNode*, int>> q;
            pair<int,int>px,py;
            q.push(make_pair(root,-1));

            int lvl = 1;
            
            while (!q.empty())
            {
                int size = q.size();
                while(size--)
                {
                    pair<TreeNode*,int> currnode = q.front();
                    q.pop();
                    TreeNode *f = currnode.first;
                    int s = currnode.second;
                    
                    if (f->val == x) px.first = s,px.second = lvl;
                    if (f->val == y) py.first = s,py.second = lvl;
                    
                    if (f->left != NULL) 
                        q.push({ f->left,f->val});
                    
                    if (f->right != NULL) 
                        q.push({ f->right,f->val});
                }
                
                lvl++;
            }
            
            if(px.first!=py.first and px.second == py.second)
                return true;
            
            return false;
        }
};