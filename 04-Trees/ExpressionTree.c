#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct list
{
    char *info;

    struct list *left, *right;

};

typedef struct list node;


int evaluate(node* root)
{
	int l_val = 0, r_val = 0;


	// Empty tree

	if (!root)

		return 0;


	// leaf node i.e, an integer

	if (!root->left && !root->right)


		return atoi(root->info);


	// Evaluate left subtree

	l_val = evaluate(root->left);

	// Evaluate right subtree

	r_val = evaluate(root->right);

	// Check which operator to apply

	if ( strcmp( root->info, "+" ) == 0 )

		return l_val + r_val;

	if ( strcmp( root->info, "-" ) == 0)

		return l_val - r_val;

	if ( strcmp( root->info, "*" ) == 0)

		return l_val * r_val;

	return l_val/r_val;
}


node* create( char *info )
{
	node *newNode = (node*)malloc( sizeof(node) );

	newNode->info = info;

	newNode->left = NULL;

	newNode->right = NULL;

	return newNode;
}

//driver function to check the above program

void main()
{

	// create a syntax tree

	node *root = create( "+" );



	root->left = create( "*" );

	root->left->left = create( "5" );

	root->left->right = create( "4" );;

	root->right = create("-");

	root->right->left = create("100");

	root->right->right = create( "20" );

	printf( "\n  Value of the expression : %d ", evaluate( root ) );

	getch();
}
