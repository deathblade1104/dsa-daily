/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode curr = head,first = head;
        int sum = 0;
        curr = curr.next;
        
        while(curr != null){
            
            if(curr.val == 0 && curr!=first){
                curr.val = sum;
                first.next = curr;
                sum =0;
                first = curr;
            }
            else sum+=curr.val;
            
            curr = curr.next;
        }
        
        return head.next;
        
    }
}