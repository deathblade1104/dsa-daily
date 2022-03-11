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
private:
    ListNode *kthfromend(ListNode *head, int k)
    {
        ListNode *curr1=head;
        for(int i=0;i<k;i++)
            curr1=curr1->next;
            
        ListNode *curr2=head,*prev=NULL,*p=NULL;
        while(curr1!=NULL)
        {
            prev=curr2;
            curr2=curr2->next;
            p=curr1;
            curr1=curr1->next;
        }
        
        prev->next=NULL;        
        p->next=head;
        
        return curr2;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL or head->next==NULL or k==0)
            return head;
        
        int n=0;
        ListNode *curr=head;
        
        while(curr!=NULL)
        {
            n++;
            curr=curr->next;
        }
        
        if(k>=n and k%n==0)
            return head;
        
        else if(k>n and k%n!=0)
            return kthfromend(head,k%n);
        
        else return kthfromend(head,k);
        
    

        
        
    }
};