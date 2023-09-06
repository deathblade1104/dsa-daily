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
    int getLLSize(ListNode *head){
        
        if(head == NULL)
            return 0;
        
        ListNode *curr = head;
        int sz = 0;
        while(curr!=NULL){
            sz++;
            curr = curr->next;
        }
        
        return sz;
    }
    
    void helper(ListNode *head,vector<ListNode*>&ans,int sz, int k,int i){
        
        if(head == NULL or k<=0)
            return;
        
        ListNode *curr = head,*h1 = head;
    
        int currSz= 1;
        
        if(sz>=k){
            currSz = sz/k;
            if(sz%k)
                currSz++;
        }
        
        int remSz = sz - currSz;
        
        while(curr!=NULL and --currSz){
            curr = curr->next;
        }
        
        ListNode *h2 =  NULL;
        
        if(curr!=NULL){
            h2 = curr->next;
            curr->next = NULL;
        }
        
        ans[i] = h1;
    
        helper(h2,ans,remSz,k-1,i+1);
        return;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*>ans(k);
        
        for(int i=0;i<k;i++){
            ans[i] = NULL;
        }
        
        int sz = getLLSize(head);
        
        helper(head,ans,sz,k,0);
        return ans;
        
    }
};