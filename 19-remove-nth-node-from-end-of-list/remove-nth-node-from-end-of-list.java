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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;

        int totalLength = 0;

        while(curr != null){
            totalLength++;
            curr = curr.next;     
        }

        int pos = totalLength - n ;

        if(pos == 0) return head.next;
        curr = head;

        for(int i=1; i<pos; i++) curr = curr.next;

        curr.next = curr.next.next;
        
        return head;
    }
}