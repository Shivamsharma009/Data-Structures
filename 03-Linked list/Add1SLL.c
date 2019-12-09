// C program to Add 1 in the linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* newnode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
Node* reverseSLL(Node* head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next;
    while(curr!=NULL)
    {
    	next = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next;
    }
    return prev;
}

Node* addOneUtil(Node* head)
{
   Node* res =head;
   Node* temp;
   int carry = 1,sum;
   while(head!=NULL)
   {
   	sum = carry + head->data;
   	carry =(sum>=10)?1:0;
   	sum = sum % 10;
   	head->data = sum;
   	temp = head;
   	head = head->next;
   }
 if(carry > 0)
 {
 	temp->next = newnode(carry);
 }
return res;
}

Node* addOne(Node* head)
{
    head = reverseSLL(head);

    head = addOneUtil(head);

    return reverseSLL(head);
}

void printList(Node* node)
{
  while(node!= NULL)
  {
  	printf("%d ",node->data);
  	node = node->next;
  }
}


// Driver Program

int main()
{
  Node* head = NULL;
  head = newnode(1);
  head->next = newnode(9);
  head->next->next = newnode(9);
  head->next->next->next = newnode(9);

  printf("\nlist is \n");
  printList(head);

  head = addOne(head);
 printf("\n The Resultant list is \n ");
   printList(head);

return 0;
}
