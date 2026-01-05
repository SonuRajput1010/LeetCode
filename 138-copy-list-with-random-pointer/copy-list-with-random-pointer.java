/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {

        if(head == null) return null;
        Node curr = head;

        // 3 Steps
        // Insert new Node;
        while(curr != null){

            Node currNext = curr.next; // B
            curr.next = new Node(curr.val); // A->x
            curr.next.next = currNext; //  A->x->B
            curr = currNext;  // A->B

        }

        // Random pointer;
        curr = head;
        while(curr != null && curr.next != null){
            if(curr.random == null){
                curr.next.random = null;
            }
            else {
                curr.next.random = curr.random.next;
            } 
            curr = curr.next.next;
        }

        // Separate both linked list;

        Node newHead = head.next;
        Node newCurr = newHead;
        curr = head;

        while(newHead != null && newCurr != null){
            curr.next = curr.next == null ? null : curr.next.next;
            newCurr.next = newCurr.next == null ? null : newCurr.next.next;

            curr = curr.next;
            newCurr = newCurr.next;
        }
        return newHead;
    }
}