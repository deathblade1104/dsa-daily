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
class Solution{
	
	private: 
	bool isLeaf(TreeNode *root){
		if(!root)
		return false;
		

		if(!root->left and !root->right)
		return true;

		return false;
}



	public :

	bool helper(TreeNode *root, int&target, int&currSum){
		
		if(!root)
		return false;

		currSum+=root->val;
		
		if(isLeaf(root) and currSum==target)
		return true;
		
		bool ans = false | helper(root->left,target,currSum) | helper(root->right,target,currSum);
		currSum-=root->val;
		return ans;	
}

	bool hasPathSum(TreeNode *root,int targetSum){

	int currSum = 0;
	return helper(root,targetSum,currSum);
}

};
