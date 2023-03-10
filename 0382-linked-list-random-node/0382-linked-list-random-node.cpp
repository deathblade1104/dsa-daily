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
    int sz;
    ListNode *head;
    Solution(ListNode* h) {
        sz = 0;
        head = h;
        
        ListNode *curr = head;
        while(curr){
            sz++;
            curr = curr->next;
        }
        return;
    }
    
    int randomGen(int limit){
        return rand() % limit;
    }
    
    int getRandom() {
        
        int currNode = randomGen(sz);
        ListNode *curr = head;
        
        while(currNode--){
            curr = curr->next;
        }
        
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */