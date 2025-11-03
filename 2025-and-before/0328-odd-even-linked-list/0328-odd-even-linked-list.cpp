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
        
        ListNode *evenHead = head->next, *oddHead = head, *curr= head->next->next;
        ListNode *evenCurr= evenHead, *oddCurr = oddHead;
        bool flag = true;
        
        while(curr){
            
            if(flag){
                oddCurr->next = curr;
                oddCurr=oddCurr->next;
            }
            
            else{
                evenCurr->next = curr;
                evenCurr=evenCurr->next;
            }
            
            curr = curr->next;
            flag = !flag;
        }
        
        evenCurr->next=NULL;
        oddCurr->next = evenHead;
        return oddHead;
    }
};