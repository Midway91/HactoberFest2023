// Java program to print all 
// ancestors of a given key 
import java.util.*; 

class GfG 
{ 

// Structure for a tree node 
static class Node 
{ 
	int data; 
	Node left, right; 
} 

// A utility function to 
// create a new tree node 
static Node newNode(int data) 
{ 
	Node node = new Node(); 
	node.data = data; 
	node.left = null; 
	node.right = null; 
	return node; 
} 

// Iterative Function to print 
// all ancestors of a given key 
static void printAncestors(Node root, int key) 
{ 
	if (root == null) 
		return; 

	// Create a stack to hold ancestors 
	Stack<Node> st = new Stack<Node> (); 

	// Traverse the complete tree in 
	// postorder way till we find the key 
	while (1 == 1) 
	{ 

		// Traverse the left side. While 
		// traversing, push the nodes into 
		// the stack so that their right 
		// subtrees can be traversed later 
		while (root != null && root.data != key) 
		{ 
			st.push(root); // push current node 
			root = root.left; // move to next node 
		} 

		// If the node whose ancestors 
		// are to be printed is found, 
		// then break the while loop. 
		if (root != null && root.data == key) 
			break; 

		// Check if right sub-tree exists 
		// for the node at top If not then 
		// pop that node because we don't 
		// need this node any more. 
		if (st.peek().right == null) 
		{ 
			root = st.peek(); 
			st.pop(); 

			// If the popped node is right child of top, 
			// then remove the top as well. Left child of 
			// the top must have processed before. 
			while (!st.isEmpty() && st.peek().right == root) 
			{ 
				root = st.peek(); 
				st.pop(); 
			} 
		} 

		// if stack is not empty then simply 
		// set the root as right child of 
		// top and start traversing right 
		// sub-tree. 
		root = st.isEmpty() ? null : st.peek().right; 
	} 

	// If stack is not empty, print contents of stack 
	// Here assumption is that the key is there in tree 
	while (!st.isEmpty()) 
	{ 
		System.out.print(st.peek().data + " "); 
		st.pop(); 
	} 
} 

// Driver code 
public static void main(String[] args) 
{ 
	// Let us construct a binary tree 
	Node root = newNode(1); 
	root.left = newNode(2); 
	root.right = newNode(7); 
	root.left.left = newNode(3); 
	root.left.right = newNode(5); 
	root.right.left = newNode(8); 
	root.right.right = newNode(9); 
	root.left.left.left = newNode(4); 
	root.left.right.right = newNode(6); 
	root.right.right.left = newNode(10); 

	int key = 6; 
	printAncestors(root, key); 
} 
} 

// This code is contributed 
// by prerna saini 
