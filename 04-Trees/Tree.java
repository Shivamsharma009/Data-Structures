// Java program to create a custom tree from a given set of links. 
	
// The main class that represents tree and has main method 
public class Tree { 
	
	private TreeNode root; 
	
	/* Returns an array of trees from links input. Links are assumed to 
	be Strings of the form "<s> <e>" where <s> and <e> are starting 
	and ending points for the link. The returned array is of size 26 
	and has non-null values at indexes corresponding to roots of trees 
	in output */
	public Tree[] buildFromLinks(String [] links) { 
			
		// Create two arrays for nodes and forest 
		TreeNode[] nodes = new TreeNode[26]; 
		Tree[] forest = new Tree[26];		 
	
		// Process each link 
		for (String link : links) { 
				
			// Find the two ends of current link 
			String[] ends = link.split(" "); 
			int start = (int) (ends[0].charAt(0) - 'a'); // Start node 
			int end = (int) (ends[1].charAt(0) - 'a'); // End node			 
						
			// If start of link not seen before, add it two both arrays 
			if (nodes[start] == null) 
			{				 
				nodes[start] = new TreeNode((char) (start + 'a')); 
				
				// Note that it may be removed later when this character is 
				// last character of a link. For example, let we first see 
				// a--->b, then c--->a. We first add 'a' to array of trees 
				// and when we see link c--->a, we remove it from trees array. 
				forest[start] = new Tree(nodes[start]);											 
			} 
			
			// If end of link is not seen before, add it to the nodes array 
			if (nodes[end] == null)							 
				nodes[end] = new TreeNode((char) (end + 'a'));								 
			
			// If end of link is seen before, remove it from forest if 
			// it exists there. 
			else forest[end] = null; 

			// Establish Parent-Child Relationship between Start and End 
			nodes[start].addChild(nodes[end], end); 
		}		 
		return forest; 
	} 
	
	// Constructor 
	public Tree(TreeNode root) { this.root = root; } 
	
	public static void printForest(String[] links) 
	{ 
		Tree t = new Tree(new TreeNode('\0')); 
		for (Tree t1 : t.buildFromLinks(links)) { 
		if (t1 != null) 
		{ 
			t1.root.printTreeIdented(""); 
			System.out.println(""); 
		} 
		} 
	}		 
	
	// Driver method to test 
	public static void main(String[] args) { 
		String [] links1 = {"a b", "b c", "b d", "a e"}; 
		System.out.println("------------ Forest 1 ----------------"); 
		printForest(links1);	 
		
		String [] links2 = {"a b", "a g", "b c", "c d", "d e", "c f", 
							"z y", "y x", "x w"}; 
		System.out.println("------------ Forest 2 ----------------"); 
		printForest(links2);	 
	} 
} 

// Class to represent a tree node 
class TreeNode {	 
	TreeNode []children; 
	char c; 
	
	// Adds a child 'n' to this node 
	public void addChild(TreeNode n, int index) { this.children[index] = n;} 
	
	// Constructor 
	public TreeNode(char c) { this.c = c; this.children = new TreeNode[26];} 
	
	// Recursive method to print indented tree rooted with this node. 
	public void printTreeIdented(String indent) {		 
			System.out.println(indent + "-->" + c); 
			for (TreeNode child : children) { 
			if (child != null) 
				child.printTreeIdented(indent + " |"); 
			}		 
	}	 
} 
