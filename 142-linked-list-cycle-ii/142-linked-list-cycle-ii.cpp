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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)
            return head;
        
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast)
            {
                ListNode *temp = head;
                while(slow!=temp)
                {
                    slow= slow->next;
                    temp = temp->next;
                }
                
                return temp;
            }
        }
        
        return NULL;
    }
};