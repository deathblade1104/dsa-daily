/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL or head->next == NULL)
            return head;
        
        
        ListNode *first,*second, *curr;
        first=second=curr=head;
        
        int counter=1;
        
        while(curr!=NULL)
        {
            if(counter<k)
                first=first->next;
            
            if(counter>k)
                second=second->next;
            
            counter++;
            curr=curr->next;
        }
                
        swap(first->val, second->val);
        return head;
    }
};