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
    int itr=0;
    
    TreeNode *getAns(int start, int end){
        if(start > end)
            return NULL;
        
        int mid = (start + end)/2;
        
        TreeNode *curr = new TreeNode(mp[mid]);
        curr->left = getAns(start,mid-1);
        curr->right = getAns(mid+1,end);
        
        return curr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        int i=0;
        ListNode *curr = head;
        
        while(curr)
        {
            mp[i] = curr->val;
            curr = curr->next;
            i++;
        }
        int n = mp.size();
        return getAns(0,n-1);
    }
};