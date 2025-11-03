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
    ListNode *get_middle(ListNode *head)
    {
        
        if(!head or !head->next)
            return head;
        
        ListNode *slow=head,*fast=head;
        
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            slow= slow->next;
        }
        
        return slow;
        
    }
    
    ListNode *rev(ListNode *head)
    {
        ListNode *prev=NULL,*curr=head, *nxt;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            
            prev=curr;
            curr= nxt;            
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode *mid= get_middle(head);
        ListNode *head2 = mid->next;
        mid->next = NULL;        
        head2= rev(head2);
        
        ListNode *curr1=head, *curr2=head2, *temp1, *temp2;
        
        while(curr1 and curr2)
        {
            temp1 = curr1->next;
            temp2 = curr2->next;
            
            curr1->next=curr2;
            curr2->next=temp1;
            
            curr1=temp1;
            curr2=temp2;
        }
        
        return;
    }
};