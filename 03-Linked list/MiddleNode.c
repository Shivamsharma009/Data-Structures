// C program to find Middle Node in Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void push(Node** head_ref,int newdata)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->next = (*head_ref);
	(*head_ref)   = newnode;
}

int MiddleNode(Node* head)
{
	Node* slow,*fast;
	for(slow = head,fast = head;fast && fast->next;fast = fast->next->next,slow = slow->next);
		return slow->data;
}

void printList(Node* node)
{
	while(node)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}

// Driver Program
int main()
{
	Node* a = NULL;
	push(&a,6);
	push(&a,5);
	push(&a,4);
	push(&a,3);
	push(&a,2);

	printList(a);

printf("\n The Middle Node Element is %d ",MiddleNode(a));

return 0;
}








