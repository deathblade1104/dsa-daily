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
        while(curr1!=NULL or curr2!=NULL or carry==1)
        {
            int sum=0;
            
            if(curr1)
            {
                sum+=curr1->val;
                curr1=curr1->next;
            }
            
            if(curr2)
            {
                sum+=curr2->val;
                curr2=curr2->next;
            }
            
            if(carry)
            {
                sum+=carry;
                carry=0;
            }
            
            if(sum>=10)
            {
                carry=1;
                sum-=10;
            }
            
            curr->next=new ListNode(sum);
            
            curr=curr->next;            
        }
    
        
        return ans->next;
    }
};