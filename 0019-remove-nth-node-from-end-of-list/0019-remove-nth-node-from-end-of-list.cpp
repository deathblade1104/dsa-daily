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
    
    ListNode* reverseLL(ListNode* head){
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *prev=nullptr,*next,*curr = head;
        
        while(curr!=nullptr){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        head = reverseLL(head);
        
        ListNode *curr=head,*prev=nullptr,*next=nullptr;
        
        if(n == 1)
            return reverseLL(head->next);
        
        for(int i=0;i<n-1;i++){
            prev = curr;
            curr = curr->next;
        }
        
        next = curr->next;
        
        if(prev!=nullptr){
            prev->next = next;
        }
        
        //delete(curr);
        
        return reverseLL(head);
    }
};