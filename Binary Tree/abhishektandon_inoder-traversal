// Date: 01-10-2020

#include <iostream>
using namespace std;

// Code outputs the inorder traversal for the following tree

/*            5
            /   \
          10    15
         /  \   / \
       20   25 30  35
*/
        
// Inorder traversal: 20 10 25 5 30 15 35

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

void Inorder(struct node * p) {
    if(p) {
        if(p->left)
           Inorder(p->left);
        cout<<(p->data)<<" ";
        if(p->right)
           Inorder(p->right);
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
        
    Inorder(root);
    return 0;
}
