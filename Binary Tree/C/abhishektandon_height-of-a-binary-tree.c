// Date: 01-10-2020
// Hacktober Fest 2020

# include <stdio.h>
# include <stdlib.h>
// Code outputs the total number of nodes, leaves and height of the following tree

/*            5
            /   \
          10    15
         /  \   / \
       20   25 30  35
*/

// Number of nodes: 7
// Height of tree: 2

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int x) {
    struct node * p = (struct node *) malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = x;
    return p;
}

int height(struct node * p) {
    
    // height of tree = 0 if node is null or a leaf
    // height of tree = max(left subtree, right subtree) otherwise
    
    if(!p)
        return 0;
    else if(p->left == NULL && p->right == NULL)
        return 0;
    else {
        int l = height(p->left);
        int r = height(p->right);
        return (l>r ? l:r)+1;
    }
}

int main() {
    struct node * root = createNode(5);
    root->left = createNode(10);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->left->right = createNode(25);
    root->right->left = createNode(30);
    root->right->right = createNode(35);
    
    int h = height(root);
    
	printf("Height of tree: %d\n", h);
	
	return 0;
}