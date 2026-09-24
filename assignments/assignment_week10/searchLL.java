public class searchLL {
    static class Node{
	int data ;
	Node next;

    	Node(int data) {
   	    this.data = data;
	    this.next = null;
        }
    }

    static boolean checklist (Node head1, Node head2) {
	if (head1 == null) {
	    return true;
	}

	Node p1 = head1;
	Node p2 = head2;
	Node l2 = head2;

	while (p2!=null) {
	    if (p1.data == p2.data) {
		p1=p1.next;
		p2=p2.next;
	    }

	    else {
		l2 = l2.next;
		p2 = l2;
		p1 = head1;
	    }
	    
	    if(p1==null) return true;
	}

	return false;

   }

     static Node createList(int[] arr) {

        if (arr.length == 0) {
            return null;
        }

        Node head = new Node(arr[0]);
        Node current = head;

        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current = current.next;
        }

        return head;
    }

    public static void main(String[] args) {

        Node head1 = createList(new int[]{1, 2, 3});
        Node head2 = createList(new int[]{1, 2, 2, 1, 2, 3});

        if (checklist(head1, head2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}