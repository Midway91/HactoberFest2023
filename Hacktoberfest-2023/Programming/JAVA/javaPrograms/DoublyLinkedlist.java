public class DoublyLinkedlist {
    private Node head;
    private Node tail;
    private int size;
    
    private class Node{
        private int val;
        private Node prev;
        private Node next;

        //constructor
        public Node(int val){
            this.val=val;
        }

        public Node(int val , Node prev , Node next){
            this.val=val;
            this.next=next;
            this.prev=prev;
        }
    }

    public DoublyLinkedlist(){
        this.size=0;
    }

    //creation
    public  void insertfirst(int val){
        Node node=new Node(val);
        node.next=head;
        node.prev=null;
        if(head!=null){
            head.prev=node;
        }
        head=node;
        
    }

    public void display(){
        
    }

    public static void main(String[] args){

    }
}
