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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        a++;
        b++;
        
        ListNode *prev = nullptr,*next = nullptr,*curr = list1;
        
        for(int i=1;i<=b;i++){
            
            if(i<a)
                prev = curr;
            
            
            ListNode *temp = curr->next;
            
            if(i == b)
                next = temp;
            
            swap(curr,temp);
            if(i>=a){
                temp->next = nullptr;
                delete(temp);
            }
            

        }
        
        
        curr = list2;
        while(curr->next!=nullptr){
            curr= curr->next;
        }
        
        curr->next = next;
        ListNode *head = list1;
        prev->next = list2;
        

        
        return head;
    
        
    }
};