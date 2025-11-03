class Solution{
	public : 
	vector<vector<int>>levelOrder(TreeNode *root){

		vector<vector<int>>ans;
		if(root == nullptr)
		return ans;
		
		queue<TreeNode*>q;
		q.push(root);
        
        
		
		while(q.size()){
            int sz = q.size();
            
            vector<int>currAns;
            while(sz--){

                TreeNode *curr = q.front();
                q.pop();
                
                currAns.push_back(curr->val);

                if(curr->left!=nullptr)
                q.push(curr->left);

                if(curr->right!=nullptr)
                q.push(curr->right);		

            }
            ans.push_back(currAns);
        }

        return ans;
    }
};
