class Solution {
	
	private: 
	int helper(TreeNode *root, int&ans){

		if(!root)
			return 0;

		int l = helper(root->left,ans),r = helper(root->right, ans);
		ans = max(ans,l+r);
		return max(l,r) + 1;
}
	public : 
	int diameterOfBinaryTree(TreeNode *root){
		int ans = 0;
		helper(root,ans);
		return ans;
}


};
