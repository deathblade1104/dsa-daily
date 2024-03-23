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
    
    ListNode* getMid(ListNode *head){
    
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *curr= head, *prev = nullptr, *nxt;
        
        while(curr!=nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2){
        
        ListNode *curr1 = head1, *curr2 = head2;
        
        while(curr1!=nullptr and curr2!=nullptr){
            
            ListNode *nxt1 = curr1->next, *nxt2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = nxt1;
            
            curr1 = nxt1;
            curr2 = nxt2;
        }
        
        
        return head1;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return;
        
        ListNode *mid = getMid(head);
        ListNode *head2 = mid->next;
        mid->next = nullptr;
        
        head2 = reverse(head2);
        
        head  = merge(head,head2);
        
        return;
        
        
    }
};