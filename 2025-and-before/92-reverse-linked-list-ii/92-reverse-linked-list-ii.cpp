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
    void rev(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *nxt;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nxt;
        }
        
        return ;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head or !head->next or left>=right)
            return head;
        
        int count=1;
        
        ListNode *p=NULL, *first=NULL, *second=NULL , *nxt =NULL , *curr=head;
        
        while(count<=left)
        {
            p = first;
            first = curr;
            curr= curr->next;
            
            count++;
        }
        
        while(count<=right)
        {
            second= curr;
            curr= curr->next;   
            count++;
        }
        
        nxt = second ->next;
        second ->next = NULL;
        rev(first);
        
        if(p)
            p->next = second;
        
        first->next = nxt;
        
        if(left!=1)
            return head;
        
        return second;
        
        
        
        
    }
};