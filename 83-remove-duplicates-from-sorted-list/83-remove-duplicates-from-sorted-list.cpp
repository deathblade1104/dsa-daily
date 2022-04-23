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
        ListNode *curr=head;
        
        while(curr)
        {
            int x = curr->val;
            
            ListNode *temp=curr->next;
            
            while(temp and temp->val==x)
            {
                ListNode *temp2=temp->next;
                curr->next=temp2;
                
                delete(temp);
                temp=temp2;
            }
            
            curr=curr->next;            
        }
        
        return head;
        
    }
};