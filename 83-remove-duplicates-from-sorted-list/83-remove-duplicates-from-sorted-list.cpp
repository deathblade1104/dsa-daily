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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *first=head, *second=head->next;        
        
        while(second!=NULL)
        {
            if(first->val==second->val)
            {
                ListNode *temp=second;
                second=temp->next;
                
                delete(temp);
                first->next=second;
            }
            
            else
            {
                first=second;
                second=second->next;
            }
        }
        
        return head;
        
    }
};