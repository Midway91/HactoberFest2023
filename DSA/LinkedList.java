package DSA;

public class LinkedList {
    Node head;
    private int size;

    LinkedList() {
        this.size = 0;
    }

    class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
            this.next = null;
        }
    }

    public void printlist() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }
        Node currNode = head;
        while (currNode != null) {
            System.out.print(currNode.data + " -> ");
            currNode = currNode.next;
        }
        System.out.println("null");
    }

    public void addfirst(String data) {
        Node newnode = new Node(data);
        newnode.next = head;
        head = newnode;
        size++;
    }

    public void addlast(String data) {
        Node newnode = new Node(data);
        if (head == null) {
            head = newnode;
        } else {
            Node lastnode = head;
            while (lastnode.next != null) {
                lastnode = lastnode.next;
            }
            lastnode.next = newnode;
        }
        size++;
    }

    public void deletefirst() {
        if (head == null) {
            System.out.println("List is already Empty");
            return;
        }
        head = head.next;
        size--;
    }

    public void deletelast() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head.next == null) {
            head = null;
        } else {
            Node currNode = head;
            while (currNode.next.next != null) {
                currNode = currNode.next;
            }
            currNode.next = null;
        }
        size--;
    }

    public int getSize() {
        return size;
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.addfirst("Dev");
        list.addfirst("Datir");
        list.printlist();
        list.addlast("From");
        list.addlast("Amravati");
        list.deletefirst();
        list.deletelast();
        list.deletelast();
        list.addlast("Datir");
        list.printlist();
        System.out.println("Size: " + list.getSize());
    }
}
