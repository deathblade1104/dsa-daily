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
    ListNode* oddEvenList(ListNode* head) {
                
        if(!head or !head->next or !head->next->next)
            return head;
        
        int count =1;        
        ListNode *odd_head = new ListNode(-1) , *curr1=odd_head, *even_head = new ListNode(-2), *curr2 = even_head , *curr = head;
        
        while(curr!=NULL)
        {
            if(count & 1)
            {
                curr1->next = curr;
                curr1 = curr1->next;
            }
            
            else
            {
                curr2->next= curr;
                curr2 = curr2->next;
            }
            
            curr=curr->next;
            count++;
        }
        
        curr2->next = NULL;
        curr1->next = even_head->next;
        
        return odd_head->next;       
        
        
        
        
    }
};