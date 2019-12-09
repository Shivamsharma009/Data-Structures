// C program for Flattering a Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *down;
}Node;

void push(Node **headref,int new_data)
{
	Node *newnode =(Node*)malloc(sizeof(Node));
	newnode->right = NULL;
	newnode->data = new_data;
	newnode->down = *headref;
	*headref = newnode;
}

void printList(Node *node)
{
	while(node!=NULL){
	printf("%d   ",node->data);
	node = node->down;
	}
}

Node *merge(Node *a,Node *b){
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	Node *result;
	if(a->data < b->data){
       result = a;
       result->down = merge(a->down,b);
   }
	else
	{
	result = b;
	result->down = merge(a,b->down);
	}
	return result;
 }


 // the Main Function the Linkd List
Node * flatten(Node* root)
{
	if(root==NULL || root->right==NULL)
		return root;
 return merge(root,flatten(root->right));
}

// Driver Function
int main()
{
	Node* root= NULL;

  push(&root,30);
  push(&root,8);
  push(&root,7);
  push(&root,5);

  push(&(root->right),20);
  push(&(root->right),10);
  push(&(root->right->right),50);
  push(&(root->right->right),22);
  push(&(root->right->right),19);

  push(&(root->right->right->right),45);
  push(&(root->right->right->right),40);
  push(&(root->right->right->right),35);
  push(&(root->right->right->right),28);

  root = flatten(root);
  printList(root);

  return 0;
}
