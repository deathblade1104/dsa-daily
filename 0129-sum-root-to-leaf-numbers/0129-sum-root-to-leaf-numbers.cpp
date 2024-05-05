class Solution{

	private : 
		bool isLeaf(TreeNode *root){
			return (root and !root->left and !root->right);
}
public : 
	
	void helper(TreeNode *root,int&ans,int&currNum){
		if(!root)
		return;
		
		currNum*=10;
		currNum+=root->val;
		
		if(isLeaf(root))
		ans+=currNum;
		
		helper(root->left,ans,currNum);
		helper(root->right,ans,currNum);
		currNum/=10;
		return;
}

	int sumNumbers(TreeNode *root){
		int ans = 0, currNum = 0;
		helper(root,ans,currNum);
        return ans;
}
};
