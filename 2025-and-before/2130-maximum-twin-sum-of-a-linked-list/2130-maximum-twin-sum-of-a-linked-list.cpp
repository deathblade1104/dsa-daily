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
    
    ListNode *reverse(ListNode *head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode *temp,*curr=head,*prev=NULL;
        
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr= temp;
        }
        
        return prev;
    }
    
    ListNode *get_mid(ListNode *head)
    {
        if(!head or !head->next )
            return head;
           
        ListNode *slow,*fast;
        slow= fast = head;
        
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    int pairSum(ListNode* head) {
        
        if(head==NULL)
            return 0;
        
        if(head -> next == NULL)
            return head->val;
        
        
        ListNode* mid = get_mid(head);
        ListNode* curr1= head, *curr2= mid->next;
        mid->next = NULL;
        
        curr2 = reverse(curr2);
        
        
        int ans =0;
        while(curr1 and curr2)
        {
            ans =max(ans, curr1->val + curr2->val);
            
            curr1= curr1->next;
            curr2= curr2->next;
        }
        
        return ans;
    }
};