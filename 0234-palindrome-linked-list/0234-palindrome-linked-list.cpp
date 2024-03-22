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
    ListNode* middleNode(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr)
            return head;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        
        return slow;
        
    }
    
    ListNode *reverse(ListNode *head){
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *prev = nullptr, *nxt = nullptr, *curr = head;
        
        while(curr){
            
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    
    bool compare(ListNode *head1,ListNode *head2){
        
        
        ListNode *curr1 = head1,*curr2 = head2;
        
        if(!curr1 and !curr2)
            return true;
        
        if((!curr1 and curr2) || (curr1 and !curr2))
            return false;
        
        while(curr1!=nullptr and curr2!=nullptr){
            
            if(curr1 and curr2 and curr1->val == curr2->val){
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            
            else return false;
        }
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return true;
        
        
        ListNode *mid = middleNode(head);
        
        ListNode *head2 = mid->next;
        mid->next = nullptr;
        
        head2 = reverse(head2);
        
        return compare(head,head2);
        
        
    }
};