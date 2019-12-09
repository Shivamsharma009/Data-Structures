// C program to Sort a Linked List of 0's,1's and 2's.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void sortList(Node* head)
{
	int count[] = {0,0,0};
	int i = 0;
	Node* temp = head;
	while(temp!= NULL)
	{
		count[temp->data]+= 1;
		temp = temp->next;
	}
 	temp = head;
     while(temp!= NULL)
     {
     	if(count[i]==0)
     		++i;
     	else
     	{
     		temp->data = i;
     		--count[i];
     		temp = temp->next;
     	}
     }
}
void push(Node** head_ref,int newdata)
{
  Node* newnode = (Node*)malloc(sizeof(Node));
  newnode->data = newdata;
  newnode->next = (*head_ref);
  (*head_ref) = newnode;
}
void printList(Node* node)
{
	while(node!= NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}

//Driver Program

int main()
{
  Node* head = NULL;
  push(&head,2);
  push(&head,1);
  push(&head,0);
  push(&head,2);
  push(&head,1);
  push(&head,2);
  push(&head,0);

  printf("\n Linked List Before Sorting \n");
  printList(head);

  printf("\n Linked List After Sorting \n ");
  sortList(head);

  printList(head);

  return 0;
}
//Time - Complexity - 0(n)
//Space - Complexity - 0(1)














