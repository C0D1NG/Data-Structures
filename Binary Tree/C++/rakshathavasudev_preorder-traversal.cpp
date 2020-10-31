// C program for preorder tree traversal 
#include <iostream> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 


/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	
	cout << node->data << " "; 


	printPreorder(node->left); 

	
	printPreorder(node->right); 
} 


int main() 
{ 
	struct Node *root = new Node(3); 
	root->left			 = new Node(4); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(7); 
	root->left->right = new Node(1); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

	return 0; 
} 
