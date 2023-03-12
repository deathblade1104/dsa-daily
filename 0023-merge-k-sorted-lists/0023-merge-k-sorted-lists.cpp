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
    struct mycomp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
        priority_queue<ListNode*,vector<ListNode*>,mycomp>pq;
        for(auto&i : lists){
            if(i)
                pq.push(i);
        }
        
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        
        
        while(pq.size()){
            
            ListNode *front = pq.top();
            pq.pop();
            
            
            if(front->next)
                pq.push(front->next);
            
            front->next = NULL;
            curr->next = front;
            curr = curr->next;
        }
        
        return head->next;
    }
};