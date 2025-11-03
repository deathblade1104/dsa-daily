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
        
        ListNode *ans = new ListNode(-1),*curr=ans;
        
        priority_queue<ListNode*,vector<ListNode*>, mycomp>pq;        
        for(auto i : lists)
            if(i!=NULL)
                pq.push(i);
        

        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
                    
            curr->next=p;
            curr=curr->next;
            
            if(p->next)
                pq.push(p->next);            
        }
        
        return ans->next;
        
    }
};