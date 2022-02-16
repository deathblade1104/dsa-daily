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
    ListNode* get_ans(ListNode *head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode *temp=head->next;
        ListNode *nxt= temp->next;
        head->next=get_ans(nxt);
        temp->next=head;
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        return get_ans(head);
        
    }
};