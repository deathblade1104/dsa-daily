class Solution{
		private: 
			bool isLeaf(TreeNode *curr){
				
				if(curr == nullptr)
					return false;

				if(curr->left == nullptr and curr->right== nullptr)
					return true;

                return false;
            }

		public: 
		
            int minDepth(TreeNode *root){

                if(root == nullptr)
                    return 0;

                queue<TreeNode*>q;
                int ans = 1;
                q.push(root);

                while(q.size()){
                    int sz = q.size();
                    while(sz--){

                        TreeNode *curr = q.front();
                        q.pop();

                        if(isLeaf(curr))
                            return ans;

                        if(curr->left)
                            q.push(curr->left);

                        if(curr->right)
                            q.push(curr->right);
                        }
                    ans++;
                }
                
                return -1;
            }

};
