// path -> store list data in ArrayList ->invoke size() method check condition

class GFG
{
	int isLengthEvenorOdd(Node head1)
	{
	    //Add your code here.
	    Node temp = head1;
	    ArrayList<Integer> ll = new ArrayList<Integer>();
	    while(temp!=null){
	        ll.add(temp.data);
	        temp = temp.next;
	    }
	    
	    if(ll.size()%2 == 0) return 0;
	    
	    return 1;
	    
	}
}
