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
        
    bool isSameTree(ListNode *head, TreeNode* q) {
        if(head==NULL)
            return true;
        if(q==NULL)
            return false;
        
        if(head->val == q->val)
            return isSameTree(head->next,q->left) or isSameTree(head->next,q->right);
        else
            return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {        
        if(!root)
            return false;
        
        return isSameTree(head, root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }

};