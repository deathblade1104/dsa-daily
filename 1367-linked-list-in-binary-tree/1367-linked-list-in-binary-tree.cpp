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
    bool get_ans(ListNode* curr, ListNode*head,TreeNode *root, 
                 map<pair<ListNode*,TreeNode*>,bool>&mp)
    {
        if(curr==NULL) return true;
        
        if(root==NULL) return false;
        
        pair<ListNode*,TreeNode*>p(curr,root);
        
        if(mp.find(p)!=mp.end())
            return mp[p];
            
        bool op1=false,op2=false;
        
        
        if(head->val==root->val)
            op1= get_ans(head->next,head,root->left,mp) or 
            get_ans(head->next,head,root->right,mp);
        
        else
            op1 = get_ans(head,head,root->left,mp) or 
            get_ans(head,head,root->right,mp);
        
        if(curr->val==root->val)
            op2 = get_ans(curr->next,head,root->left,mp) 
            or get_ans(curr->next,head,root->right,mp);
        
        mp[p]= op1 or op2;
        
        return mp[p];
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        map<pair<ListNode*,TreeNode*>,bool>mp;
        
        return get_ans(head,head,root,mp);
        
        
    }
};