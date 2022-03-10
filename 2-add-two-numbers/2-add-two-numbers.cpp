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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *ans=new ListNode(-1), *curr1=l1,*curr2=l2;
        ListNode *curr=ans;
        
        int carry=0;
        while(curr1!=NULL and curr2!=NULL)
        {
            int sum= curr1->val + curr2->val + carry;
            
            if(sum>=10)
            {
                carry=1;
                sum-=10;
            }
            else
                carry=0;
            
            curr->next=new ListNode(sum);
            
            curr1=curr1->next,curr2=curr2->next,curr=curr->next;            
        }
        
        while(curr1!=NULL)
        {
            
            int sum= curr1->val + carry;
            
            if(sum>=10)
            {
                carry=1;
                sum-=10;
            } 
            
            else
                carry=0;
            curr->next=new ListNode(sum);
            
            curr1=curr1->next,curr=curr->next;    
            
        }
        
        while(curr2!=NULL)
        {
            
            int sum= curr2->val + carry;
            
            if(sum>=10)
            {
                carry=1;
                sum-=10;
            }  
            else
                carry=0;
            
            curr->next=new ListNode(sum);
            
            curr2=curr2->next,curr=curr->next;    
        }
        
        if(carry==1)
        {
            curr->next=new ListNode(1);
        }
        
        return ans->next;
    }
};