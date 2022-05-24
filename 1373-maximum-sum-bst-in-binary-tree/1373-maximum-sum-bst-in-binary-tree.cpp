int ans;
class prop{
public:
    bool bst;       //to check if tree is bst
    int ma;         //max value in a tree
    int mi;         //min value in an tree
    int ms;         //current maximum sum
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
};
class Solution {
public:
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop();
        }
        prop p;
        prop pl = calcSum(root->left);                        //recursive call for left sub-tree
        prop pr = calcSum(root->right);                       //recursive call for right sub-tree
		
		//if sub-tree including this node is bst
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){
            p.bst = true;                                                      //current tree is a bst
            p.ms = pl.ms + pr.ms + root->val;          
            p.mi  = min(root->val, min(pr.mi, pl.mi));
            p.ma = max(root->val, max(pl.ma, pr.ma));
        }
		//if current tree is not a bst
        else {
            p.bst=false;
            p.ms=max(pl.ms, pr.ms);
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