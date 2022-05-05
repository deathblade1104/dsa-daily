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
    void remove_nodes(unordered_map<int,ListNode*>&mp, ListNode *start, ListNode*end, int &ps)
    {
        int t = ps;           
        
       for(ListNode *curr= start->next; curr!=end and curr!=NULL; curr= curr->next)
       {
           t+=curr->val;
           mp.erase(t);
       }
        
        start->next = end->next;
        
        return;
    }
    
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        int ps=0;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        mp[0]=dummy;
          
        ListNode *curr = head;
        while(curr!=NULL)
        { 
            ps+=curr->val;
           
            if(mp.count(ps)==1)
            {               
                ListNode *temp = curr;
                remove_nodes(mp, mp[ps], temp, ps);               
                curr=temp->next;                
            }
            
            else 
            {
                mp[ps]=curr;
                curr=curr->next;
            }            
        }
                
        return dummy->next;
    }
};