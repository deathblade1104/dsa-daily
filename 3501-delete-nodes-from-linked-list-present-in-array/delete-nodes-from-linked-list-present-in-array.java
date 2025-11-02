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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> st = new HashSet<>();
        
        for (int x : nums) 
            st.add(x);

        while (head != null && st.contains(head.val)) {
            head = head.next;
        }

        if (head == null) 
            return null;

        ListNode prev = head,curr = head.next;
        prev.next = null;

        while (curr != null) {
            ListNode nxt = curr.next;
            if (!st.contains(curr.val)){
                prev.next = curr;
                prev = curr;
                prev.next = null;
            }
            curr = nxt;
        }

        return head;
    }
}