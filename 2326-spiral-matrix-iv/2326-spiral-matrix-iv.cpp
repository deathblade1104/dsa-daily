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
    int r1,c1,r2,c2;
    
    void spiralTraverse(ListNode *head,vector<vector<int>>&ans){
        
        if(!head )
            return;
        
        for(int i=c1;i<=c2 and head;i++)
        {
            ans[r1][i] = head->val;
            head = head->next;
        }
        
        r1++;
        
        for(int i=r1;i<=r2 and head;i++){
            ans[i][c2] = head->val;
            head = head->next;
        }
        
        c2--;
        
        for(int i=c2;i>=c1 and head;i--){
            ans[r2][i] = head->val;
            head = head->next;
        }
        
        r2--;
        
        for(int i=r2;i>=r1 and head;i--){
            ans[i][c1] = head->val;
            head = head->next;
        }
        
        c1++;
        
        spiralTraverse(head,ans);
        return;
    }
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        r1 = c1 = 0;
        r2 = m-1;
        c2 = n-1;
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        spiralTraverse(head,ans);
        
        return ans;
        
        
    }
};