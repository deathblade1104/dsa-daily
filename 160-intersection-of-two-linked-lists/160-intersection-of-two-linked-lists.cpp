/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB)
            return NULL;
        
        ListNode *curr1 = headA, *curr2=headB;
        
        while(curr1!=curr2)
        {
            curr1 = (curr1 == NULL) ? headB : curr1->next;
            curr2 = (curr2 == NULL) ? headA : curr2->next;
        }
        
        return curr1;
    }
};