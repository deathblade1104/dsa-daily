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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>mp;
    
    TreeNode *helper(int start,int end){
        
        if(start>end)
            return NULL;
        
        int mid = start + ((end - start)/2);
        
        TreeNode *curr = new TreeNode(mp[mid]);
        curr->left = helper(start,mid-1);
        curr->right = helper(mid+1,end);
        mp.erase(mid);
        
        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        int sz = 0;
        ListNode *curr = head;
        
        while(curr){
            mp[sz++] = curr->val;
            curr = curr->next;
        }
        
        if(!sz)
            return NULL;
        return helper(0,sz-1);
        
    }
};