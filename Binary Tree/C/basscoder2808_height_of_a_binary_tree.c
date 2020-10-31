#include<stdio.h> 
#include<stdlib.h> 

// Structure for the nodes of our tree
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 


int height(struct node* node);
struct node* newNode(int data);
	
int main() 
{ 
	struct node *root = newNode(1); 

	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

    /* So The tree basically is 
                1
            /       \
           2         3
          /            \
        4                5
    */
	printf("Height of tree is %d\n", height(root)); 
	
	getchar(); 
	return 0; 
} 

// main function used to calculate the height of our Tree.
// This function calculates height using recursion
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int left_height = height(node->left); 
        int right_height = height(node->right); 
        if (left_height > right_height) 
            return left_height+1; 
        else return right_height+1; 
    } 
} 

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return node; 
} 
