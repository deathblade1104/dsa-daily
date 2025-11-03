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
        
        ans+= to_string(root->val) + "_";
        
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    string serialize(TreeNode* root) {
       string ans="";
        preorder(root,ans);
        
        return ans;
        
    }

    // Decodes your encoded data to tree.
    int get_num(string &data, int &curr)
    {
        string temp="";
        while(data[curr]!='_')
            temp+=data[curr++];
        
        curr++;
        
        return stoi(temp);
    }
    
    TreeNode *de_preorder(string&data, int&curr)
    {
        if(curr>=data.size())
            return NULL;
        
        if(data[curr]=='N')
        {
            curr+=2;
            return NULL;
        }
        
        TreeNode *root = new TreeNode(get_num(data,curr));
        root->left= de_preorder(data,curr);
        root->right = de_preorder(data,curr);
        
        return root;
    }
    
    TreeNode* deserialize(string data) {
        
        int curr=0;
        return de_preorder(data,curr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;