/* C++ program to construct string from binary tree*/
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node { 
	int data; 
	Node *left, *right; 
}; 

/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Iterative function to print diagonal view 
void diagonalPrint(Node* root) 
{ 
	// base case 
	if (root == NULL) 
		return; 

	// inbuilt queue of Treenode 
	queue<Node*> q; 

	// push root 
	q.push(root); 

	// push delimiter 
	q.push(NULL); 

	while (!q.empty()) { 
		Node* temp = q.front(); 
		q.pop(); 

		// if current is delimiter then insert another 
		// for next diagonal and cout nextline 
		if (temp == NULL) { 

			// if queue is empty return 
			if (q.empty()) 
				return; 

			// output nextline 
			cout << endl; 

			// push delimiter again 
			q.push(NULL); 
		} 
		else { 
			while (temp) { 
				cout << temp->data << " "; 

				// if left child is present 
				// push into queue 
				if (temp->left) 
					q.push(temp->left); 

				// current equals to right child 
				temp = temp->right; 
			} 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	Node* root = newNode(8); 
	root->left = newNode(3); 
	root->right = newNode(10); 
	root->left->left = newNode(1); 
	root->left->right = newNode(6); 
	root->right->right = newNode(14); 
	root->right->right->left = newNode(13); 
	root->left->right->left = newNode(4); 
	root->left->right->right = newNode(7); 
	diagonalPrint(root); 
} 
