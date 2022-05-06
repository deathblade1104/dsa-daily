/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        queue<Node*>q;
        q.push(root);
        
        while(q.size()>0)
        {
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                Node *t = q.front();
                q.pop();
                
                if(i<sz-1)
                    t->next = q.front();                
                
                else
                    t->next = NULL;
                
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }
            
        }
        
        return root;
    }
};