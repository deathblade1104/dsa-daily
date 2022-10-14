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
    ListNode* getMiddlePrev(ListNode* head){
        
        ListNode *prev=NULL, *slow = head, *fast = head;
       
        while(fast and fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        return prev;
    }
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head->next)
            return NULL;
        
        
        ListNode *midPrev = getMiddlePrev(head);
        ListNode *middle = midPrev->next;
        
        midPrev->next = middle->next;
        
        delete(middle);
        
        return head;
    }
};