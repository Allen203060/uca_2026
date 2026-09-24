class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class ReverseLL {
    public static ListNode reverseLL(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode res = reverseLL(head.next);
        
        head.next.next = head;
        head.next = null;
        
        return res;
    }

    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val + " -> ");
            curr = curr.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
         
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Original: ");
        printList(head);

        head = reverseLL(head);

        System.out.print("Reversed: ");
        printList(head);
    }
}
 