#include<stdio.h>
#define TRUE 1
#define FALSE 0

struct node
{
	int data ;
	struct node *left;
	struct node *right;
};

struct node* getNewNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node)); //allocating memory
	
	newNode->data = data ;
	newNode->left = NULL ;
	newNode->right = NULL;
	
	return newNode;	
}
struct node* generateBTree()
{
	struct node* root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	
	root->left->left = getNewNode(4);	
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	root->left->left->left = getNewNode(8);

	return root ;
} 
int isIdentical(struct node *first, struct node *second)
{
	if(first == NULL && second == NULL)
	{
		return TRUE;
	}
	
	if(first == NULL || second == NULL)
	{
		return FALSE;
	}

	if(isIdentical(first->left , second->left )&&
	   isIdentical(first->right, second->right)&&
	   first->data == second->data)
	{
		return TRUE ;
	}
	else
	{
		return FALSE;
	}			
}

int main(void)
{
	struct node *root1 = generateBTree();
	struct node *root2 = generateBTree();
	
	if(isIdentical(root1, root2))
	{
		printf("Both Tress are identical.\n");
	}
	else
	{
		printf("Both trees are not identical.\n");
	}
	
	root2->left->data = 10 ;
	if(isIdentical(root1, root2))
	{
		printf("Both Tress are identical.\n");
	}
	else
	{
		printf("Both trees are not identical.\n");
	}
	getchar();
	return 0 ;
}