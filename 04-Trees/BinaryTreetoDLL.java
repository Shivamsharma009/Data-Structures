// Java program to implement Binary tree to Doubly Linked List

class Node
{
	int data;
	Node left,right;
	public Node(int data)
	{
	this.data = data;
	left=right=null;
	}
}

class BinaryTreetoDLL
{
	Node root;
	Node head;
	static Node prev = null;

	void BinaryTree2DoublyLinkedList(Node root)
	{
		if(root==null)
			return; 

		BinaryTree2DoublyLinkedList(root.left);

		if(prev==null)
			head = root;
		else
		{
			prev.right = root;
			root.left = prev;
		}
		prev = root;
		BinaryTree2DoublyLinkedList(root.right);
	}
  void printList(Node node)
  {
  	while(node!=null)
  	{
  		System.out.print(node.data +"  ");
  		node = node.right;
  	}
  }
 // Driver Program
  public static void main(String[] args)
  {
  	BinaryTreetoDLL tree = new BinaryTreetoDLL();
  	tree.root = new Node(10);
  	tree.root.left = new Node(12);
  	tree.root.right = new Node(15);

  	tree.root.left.left = new Node(25);
  	tree.root.left.right = new Node(30);

  	tree.root.right.left = new Node(36);
  	tree.BinaryTree2DoublyLinkedList(tree.root);
  	tree.printList(tree.head);
  }
}