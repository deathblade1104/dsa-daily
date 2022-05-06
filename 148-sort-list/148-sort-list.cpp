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
    
    ListNode* sortList(ListNode* head) {
        ListNode *ans = new ListNode(-1),*curr=ans;
        priority_queue<ListNode*,vector<ListNode*>, mycomp>pq;        
        
        for(ListNode  *temp = head; temp!=NULL; temp=temp->next)
        pq.push(temp);
        
         while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
                    
            curr->next=p;
            p->next = NULL;
            curr=curr->next;          
        }
        
        return ans->next;
        
        
    }
};