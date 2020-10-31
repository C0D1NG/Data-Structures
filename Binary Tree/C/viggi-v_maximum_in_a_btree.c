#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
typedef struct _node{
	int val;
	struct _node *left, *right;
}node;

node* newNode(int);
node* makeTree(int);
void inOrder(node*);
int findMax(node*);
void main(){
	srand(time(0));
	printf("Hello world!\n");
	int size = 3;
	node* root = makeTree(size);
	printf("inOrder travel of tree of size %d\n", size);
	inOrder(root);
	printf("\nbiggest num : %d\n", findMax(root));
}

node* newNode(int val){
	node* temp = (node*) malloc(sizeof(node));;
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

node* makeTree(int level){
	// basic driver code to populate the tree with a random balanced binary tree 
	// numbers between -100 and 100
	if(level < 1)
		return NULL;

	int num = rand()%200 - 100;	
	
	node* root = newNode(num);
	
	printf("pushing %d\n",num);
	
	if(level == 1)
		return root;
	
	root->left = makeTree(level - 1);
	root->right = makeTree(level - 1);

	return root;	
}

void inOrder(node* root){
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->val);
	inOrder(root->right);
}

int findMax(node* root){
	// base case
	if(root == NULL) 
		return INT_MIN;
	
	// find the max value of child nodes and compare with the current node
	// and call it recursively
	int lMax = findMax(root->left);
	int rMax = findMax(root->right);
	int val = root->val;

	if(val > lMax && val > rMax)
		return val;
	if(lMax > rMax)
		return lMax;
	return rMax;
}