// C program to Reverse a Linked List
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void push(Node** head_ref,int newdata)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->next = (*head_ref);
	(*head_ref) = newnode;
}

void printList(Node* node)
{
   while(node)
   {
   	printf("%d ",node->data);
   	node = node->next;
   }
}

void ReverseList(Node** head_ref)
{
	Node* cur,*prev,*next;
	cur = *head_ref;
	prev = NULL;
	while(cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head_ref = prev;
}

//Driver Program

int main()
{
	//create a Linked List
	Node* a = NULL;
	push(&a,1);
	push(&a,2);
	push(&a,3);
	push(&a,4);
	push(&a,5);
	push(&a,6);

	printf("Without Reversing Linked List is \n ");
	printList(a);

	printf("\nReverse a Linked List is \n");
	ReverseList(&a);

	printList(a);

	return 0;
	getchar();

}
