/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        vector<int>ans;
        if(root==NULL) return ans;
        
        stack<Node*>st;
        st.push(root);
        
        while(st.size()>0)
        {
            Node *curr=st.top();
            st.pop();
            
            ans.push_back(curr->val);  
            
            vector<Node*>v=curr->children;
            int n=v.size();
            for(int i=0;i<n;i++)
            {
               if(v[i]!=NULL)
               st.push(v[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};