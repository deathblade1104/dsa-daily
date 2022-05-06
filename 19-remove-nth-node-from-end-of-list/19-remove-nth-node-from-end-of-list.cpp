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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL and n==1)
            return NULL;
        
        ListNode* first=head;
        
        for(int i=0;i<=n-1;i++)
            first=first->next;
        
        ListNode* ans=head;
        ListNode* temp=NULL;
        
        while(first!=NULL)
        {
            temp=ans;
            ans=ans->next;
            first=first->next;
        }
        
        if(temp and temp->next)
        temp->next=temp->next->next;
        
        if(ans==head)
            return head->next;
        
        delete(ans);
        
        return head;
        
        
        
        
        
        
    }
};