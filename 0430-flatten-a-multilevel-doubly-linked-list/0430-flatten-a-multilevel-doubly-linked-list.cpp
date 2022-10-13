/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
    public:
    vector<Node*>helper(Node *head) {
        
        vector<Node*>ans={head};
        
        if(!head)
            return ans;
        
        Node *temp = new Node(-1);
        temp->next = head;
        head->prev = temp;

        Node *curr = head, *prev = temp;

        while (curr!=NULL)
        {
            if (curr->child)
            {
                Node *nxt = curr->next;
                vector<Node*>p= helper(curr->child);
                curr->child = NULL;
                
                curr->next  = p[0];
                p[0]->prev = curr;
                
                p[1]->next = nxt;
                if(nxt)
                    nxt->prev = p[1];
                
                curr = nxt;
                prev = p[1];
            }
            
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        head->prev = NULL;
        temp->next = NULL;

        delete(temp);
        
       ans.push_back(prev);
       return ans;
    }
    
    Node* flatten(Node *head)
    {
        
        vector<Node*>ans = helper(head);
        return ans[0];
        
    }
};