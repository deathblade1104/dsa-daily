
class Solution {
public:
    int ans;
    struct prop
    {
        bool bst;
        int ms,mi,ma;
        
        prop()
        {
            bst = true;
            ms=0;
            mi=INT_MAX;
            ma = INT_MIN;
            
        }
    };
    
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop();
        }
        prop p;
        prop pl = calcSum(root->left);                        //recursive call for left sub-tree
        prop pr = calcSum(root->right);                       //recursive call for right sub-tree
		
		//if sub-tree including this node is bst
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){                                //current tree is a bst
            p.ms = pl.ms + pr.ms + root->val;          
            p.mi  = min(root->val, pl.mi);
            p.ma = max(root->val, pr.ma);
        }
		//if current tree is not a bst
        else {
            p.bst=false;
        }
		
        ans=max(ans, p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root){
        ans=INT_MIN;
        calcSum(root);
        return ans>0 ? ans : 0;
    }
};