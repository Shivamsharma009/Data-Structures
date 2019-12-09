// Given an ancestor matrix for binary tree, construct
// the tree.
#include <iostream>
#include <map>
using namespace std;

#define N 6

// key structure to store a binary tree node
struct Node {
	int key;
	struct Node* left;
	struct Node* right;
};

// Utility function to create a new binary tree node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Utility function to print binary tree nodes in-order fashion
void Preorder(struct Node* node)
{
	if (node != NULL) {
		cout << node->key << " ";
		Preorder(node->left);

		Preorder(node->right);
	}
}

// Function to construct a binary tree from specified ancestor matrix
struct Node* constructBT(bool mat[][N])
{
	// create an empty multi-map
	multimap<int, int> multimap;

	// Use sum as key and row numbers as values in the multi-map
	for (int i = 0; i < N; i++) {
		// find the sum of the current row
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += (int)mat[i][j];

		// insert the sum and row number into the multimap
		multimap.insert({ sum, i });
	}

	// node[i] will store node for i in constructed tree
	struct Node* node[N];
	int row;

	// the value of parent[i] is true if parent is set for i'th node
	bool parent[N];
	for (int i = 0; i < N; i++) {
		parent[i] = false;
	}

	// Traverse the multimap in sorted order (default behavior)
	for (auto it : multimap) {
		row = it.second;

		// create a new node
		node[row] = newNode(row);

		// if leaf node, do nothing
		if (it.first == 0)
			continue;

		// traverse row
		for (int i = 0; i < N; i++) {
			// do if parent is not set and ancestor exits
			if (parent[i] == false && mat[row][i]) {
				// check for the unoccupied node
				if (node[row]->left == nullptr)
					node[row]->left = node[i];
				else
					node[row]->right = node[i];

				// set parent for i'th node
				parent[i] = true;
			}
		}
	}

	// last processed node is the root
	return node[row];
}

// Construct a Binary Tree from Ancestor Matrix
int main()
{
	bool mat[N][N] = {
		{ 0, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0 ,1},
		{ 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{0, 0, 0, 0, 0 , 0 },
		{0, 0, 0, 0, 0, 0},
	};

	struct Node* root = constructBT(mat);
	Preorder(root);

	return 0;
}
