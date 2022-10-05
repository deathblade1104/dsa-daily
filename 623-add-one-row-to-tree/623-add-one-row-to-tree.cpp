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
        TreeNode* helper(TreeNode *root, int&val, int&givenDepth, int currDepth, bool isLeft)
        {

            if (givenDepth == currDepth)
            {

                TreeNode *curr = new TreeNode(val);
                //cout<<curr->val<<" "<<currDepth<<endl;
                
                if(isLeft)
                curr->left =  helper(root,val,givenDepth,currDepth+1,1);
                
                else
                curr->right = helper(root,val,givenDepth,currDepth+1,0);
                
                return curr;
            }
            
            else {
                
                if(!root)
                    return NULL;
                
                //cout<<root->val<<" "<<currDepth<<endl;
                
                TreeNode *l = helper(root->left,val,givenDepth,currDepth+1,1);
                TreeNode *r = helper(root->right,val,givenDepth,currDepth+1,0);
                
                root->left = l;
                root->right = r;
                
                return root;
            }
        }

    TreeNode* addOneRow(TreeNode *root, int val, int depth) {
        
        return helper(root,val,depth,1,1);
        
    }
};