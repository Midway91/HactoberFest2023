class LinkedList { 
	Node head;
	
  public class Node { 
		int data; 
		Node next; 
		Node(int data) { 
			this.data = data; 
			next = null; 
		}
	}

	public void push(int newData) { 
		Node newNode = new Node(newData); 
		newNode.next = head;
		head = newNode;
	}

	public void detectLoop(){ 
		Node slow = head
    Node fast = head; 
		int flag = 0; 
		while (slow != null && fast != null && fast.next != null) { 
			slow = slow.next; 
			fast = fast.next.next; 
			if (slow == fast){ 
				flag = 1;
				break;
			}
		} 
		if (flag == 1){
			System.out.println("Loop found"); 
    }
		else{
			System.out.println("Loop not found"); 
    }
  } 
}
