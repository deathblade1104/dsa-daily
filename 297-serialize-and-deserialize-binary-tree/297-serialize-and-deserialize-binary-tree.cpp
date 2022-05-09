/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode *root, string&ans)
    {
        if(!root)
        {
            ans+="N_";
            return;
        }
        
        ans+=to_string(root->val) + "_";
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    
    int get_val(string &data, int &itr)
    {
        string res = "";
        
        while(data[itr]!='_')
            res+=data[itr++];
        
        itr++;
        
        return stoi(res);
    }
    
    TreeNode *constructTree(string&data, int&itr)
    {        
        if(data[itr]=='N')
        {
            itr+=2;
            return NULL;
        }
        
        int curr = get_val(data, itr);
        
        TreeNode *root = new TreeNode (curr);
        
        root->left = constructTree(data,itr);
        root->right = constructTree(data,itr);
        
        return root;               
    }
    
    TreeNode* deserialize(string data) {
        int itr =0;
        
        return constructTree(data,itr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));