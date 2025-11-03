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
    ListNode *getSmaller(ListNode* head,int x){
        
        ListNode *curr = head, *prev = NULL;
        ListNode *newHead = new ListNode(-1), *newCurr = newHead;
        
        while(curr!=NULL){
            ListNode *nxt = curr->next;
            if(curr->val < x) {

                curr->next = NULL;
                newCurr->next = curr;
                newCurr = newCurr->next;
                
                if(prev!=NULL) {
                    prev->next = nxt;
                }
                else{
                    head = nxt;
                }
                
            } else {
                prev = curr;
            }
            curr = nxt;
            
        }
        
        if(newHead->next==NULL)
            return head;
        
        if(head!=NULL)
                newCurr->next = head;
        
        return newHead->next;
    }
    
    
    ListNode* partition(ListNode* head, int x) {
        return getSmaller(head,x);
    }
};