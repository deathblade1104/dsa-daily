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
    
    ListNode *rev(ListNode *first , ListNode *second)
    {
        ListNode *curr= first, *prev=NULL, *temp;
        
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        
        
        int count =1;
        ListNode *curr = head;
        
        while(curr!=NULL and count <k)
        {
            count++;
            curr=curr->next;
        }
        
        if(curr==NULL)
            return head;
        else
        {
            ListNode *temp = curr->next;
            curr->next = NULL;
            ListNode *rev_head = rev(head,curr);            
            head->next = reverseKGroup(temp,k);
            
            return rev_head;
        }
    }
};