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
    
    ListNode *rev(ListNode *head){
        
        if(head==NULL or head->next==NULL)
            return head;
        
        
        ListNode *prev = NULL,*curr = head;
        
        while(curr!=NULL){
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL or head->next == NULL or left == right)
            return head;
        
        int currIdx = 1;
        ListNode *curr = head,*p1=NULL,*start=NULL,*end=NULL,*p2=NULL;
        
        while(currIdx<=right){
            
            if(currIdx<=left){
                if(currIdx == left){
                    if(p1!=NULL){
                        p1->next =NULL;
                    }

                    start = curr;
                }
                else{
                     p1 = curr;
                }
            }
            
            if(currIdx == right){
                end = curr;
                if(curr->next!=NULL){
                    p2 = curr->next;
                }
                
                curr->next= NULL;
            }
            
            curr = curr->next;
            currIdx++;
        }
        
        
        
        end = rev(start);
        
        if(p1!=NULL)
            p1->next = end;
        
        start->next = p2;
        
        
        return left == 1? end : head;
        
    }
};