#include <stdio.h> 
#include <stdlib.h> 

// Structure which will act as a node for our trees
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 


struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 


/* Inorder prints our tree in ascendingn order
    Basically Inorder follows the order left -> root -> right     
*/
void printInorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 
	printf("%d ", node->data); 
	printInorder(node->right); 
} 


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

	printf("Inorder traversal of binary tree is \n"); 
	printInorder(root); 
	getchar(); 
	return 0; 
} 
