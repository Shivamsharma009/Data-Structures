// Java program to Generate a Random Binary Tree
import java.util.*; 
import java.lang.*; 
import java.io.*; 

class RandomBinaryTree 
{ 
static class Node 
{ 
	int data; 
	int children; 
	Node left, right; 
} 

static Node newNode(int data) 
{ 
	Node temp = new Node(); 
	temp.data = data; 
	temp.left = temp.right = null; 
	temp.children = 0; 
	return temp; 
} 

// This is used to fill children counts. 
static int getElements(Node root) 
{ 
	if (root == null) 
		return 0; 
	return getElements(root.left) + 
		getElements(root.right) + 1; 
} 

// Inserts Children count for each node 
static Node insertChildrenCount(Node root) 
{ 
	if (root == null) 
		return null; 

	root.children = getElements(root) - 1; 
	root.left = insertChildrenCount(root.left); 
	root.right = insertChildrenCount(root.right); 
	return root; 
} 

// returns number of children for root 
static int children(Node root) 
{ 
	if (root == null) 
		return 0; 
	return root.children + 1; 
} 

// Helper Function to return a random node 
static int randomNodeUtil(Node root, int count) 
{ 
	if (root == null) 
		return 0; 

	if (count == children(root.left)) 
		return root.data; 

	if (count < children(root.left)) 
		return randomNodeUtil(root.left, count); 

	return randomNodeUtil(root.right, 
		count - children(root.left) - 1); 
} 

// Returns Random node 
static int randomNode(Node root) 
{ 

	int count = (int) Math.random() * 
					(root.children + 1); 
	return randomNodeUtil(root, count); 
} 

// Driver Code 
public static void main(String args[]) 
{ 
	
	// Creating Above Tree 
	Node root = newNode(10); 
	root.left = newNode(20); 
	root.right = newNode(30); 
	root.left.right = newNode(40); 
	root.left.right = newNode(50); 
	root.right.left = newNode(60); 
	root.right.right = newNode(70); 

	insertChildrenCount(root); 

	System.out.println( "A Random Node From Tree : " + 
									randomNode(root)); 
} 
} 


