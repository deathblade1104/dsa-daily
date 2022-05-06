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
    
    int find_length(ListNode *head)
    {
        if(!head)
            return 0;
        
        ListNode *curr=head;
        int ans=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            ans++;
        }
        
        
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = find_length(head);
        
        if(n!=0)
            k=k%n;
        
        if(k==0 or n==0)
            return head;
        
        ListNode *last=head;
        
        for(int i=0;i<k-1;i++)
            last = last->next;
        
        ListNode *kth=head,*prev=NULL;
        
        while(last->next != NULL)
        {
            prev = kth;
            kth = kth->next;
            last = last ->next;
        }
        
        prev->next=NULL;
        last->next= head;
        
        return kth;
             
        
        
    }
};