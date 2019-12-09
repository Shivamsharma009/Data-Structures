//C program to Merge Sort on Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void Partition(Node* source,Node** frontref,Node** backref);
Node* SortedMerge(Node* a,Node* b);


void MergeSort(Node** headref)
{
	Node* head = *headref;
	Node* a;
	Node* b;
	if((head == NULL)||(head->next == NULL))
	{
		return;
	}
    Partition(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headref = SortedMerge(a,b);
}

Node* SortedMerge(Node* a,Node* b)
{
	Node* result;
	if(a == NULL)
		return b;
  else  if(b == NULL)
    	return a;
    if(a->data <= b->data)
    {
    	result = a;
    	result->next = SortedMerge(a->next,b);
    }
    else
    {
    	result = b;
    	result->next = SortedMerge(a,b->next);
    }
    return (result);
}

void Partition(Node* source,Node** frontref,Node** backref)
{
	Node* slow;
	Node* fast;
	slow = source;
	fast = source->next;
	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void printList(Node* node)
{
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}

void push(Node** headref,int newdata){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->next = (*headref);
	(*headref) = newnode;
}
int main()
{

Node* a = NULL;

push(&a,15);
push(&a,10);
push(&a,5);
push(&a,20);
push(&a,3);
push(&a,2);


printf("Linked List Before using Merge Sort\n");
printList(a);

MergeSort(&a);

printf("\nSorted Linked List is using Merge Sort\n");

printList(a);
getchar();

return 0;
}
