public class LinkedListRecursive   
{  
// first node or head of the list  
static LinkedListNode head;   
  
static class LinkedListNode   
{  
// for containing the value of the node  
int val;  
  
// the next pointer points to the other node of the list or null  
LinkedListNode next;  
  
// constructor of the class  
LinkedListNode(int d)  
{  
// assigning the values  
val = d;  
next = null;  
}  
}  
  
// method where actual reversing of the list takes place  
public LinkedListNode reverseList(LinkedListNode head)  
{  
// if the head is null or the list  
// contains only one element then reversing the list  
// does not have any impact on the list. Therefore, we   
// can return the original list without performing any operation  
if (head == null || head.next == null)  
{  
return head;  
}  
  
// reverse the rest (r) of the list and place  
// the first element of the list at the last   
LinkedListNode r = reverseList(head.next);  
head.next.next = head;  
  
  
head.next = null;  
  
// fixing the head pointer  
return r;  
}  
  
/* Method to display the linked list */  
public void printList(LinkedListNode h)  
{  
LinkedListNode t = h;  
while (t != null)   
{  
System.out.print(t.val + " ");  
  
// moving to the next node  
t = t.next;  
}  
  
System.out.println();  
}  
  
  
// main method  
public static void main(String argvs[])  
{  
// creating an object of the class LinkedListRecursive  
LinkedListRecursive listObj = new LinkedListRecursive();  
  
listObj.head = new LinkedListNode(4);  
  
listObj.head.next = new LinkedListNode(6);  
  
listObj.head.next.next = new LinkedListNode(7);  
  
listObj.head.next.next.next = new LinkedListNode(1);  
  
listObj.head.next.next.next.next = new LinkedListNode(5);  
  
listObj.head.next.next.next.next.next = new LinkedListNode(8);  
  
listObj.head.next.next.next.next.next.next = new LinkedListNode(3);  
  
listObj.head.next.next.next.next.next.next.next = new LinkedListNode(2);  
  
  
System.out.println("The Linked list before reversal is: ");  
listObj.printList(head);  
head = listObj.reverseList(head);  
System.out.println(" ");  
System.out.println("After reversal, the linked list is: ");  
listObj.printList(head);  
}  
}  
