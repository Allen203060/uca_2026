public class intersectionLL {
    static class Node{
	int data;
	Node next;
	Node (int data) {
	    this.data = data;
	    this.next = null;
	}
    }

    static Node intersection(Node head1, Node head2) {
	Node p1 = head1;
	Node p2 = head2;
	Node dummy = new Node(0);
	Node tail = dummy;
	while(p1!=null && p2!=null) {
	    if (p1.data == p2.data) {
		Node temp = new Node(p1.data);
		tail.next = temp;
		p1=p1.next;
		p2=p2.next;
		tail = tail.next;
	    }
	    
	    else if (p1.data < p2.data) {
		p1 = p1.next;
	    }
	    else p2 = p2.next;
	}
	return dummy.next;
   }

    static void printLL(Node head) {
	while (head!=null) {
	    System.out.print(head.data);
	    if (head.next!=null) {
		System.out.print("->");
	    }
	    head = head.next;
	}
	System.out.println();
   }

     public static void main(String[] args) {

        // List 1:
        // 1 -> 2 -> 2 -> 4 -> 6
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(4);
        head1.next.next.next.next = new Node(6);

        // List 2:
        // 2 -> 2 -> 3 -> 6 -> 8
        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(3);
        head2.next.next.next = new Node(6);
        head2.next.next.next.next = new Node(8);

        System.out.println("List 1:");
        printLL(head1);

        System.out.println("List 2:");
        printLL(head2);

        Node result = intersection(head1, head2);

        System.out.println("Intersection:");
        printLL(result);
    }
}