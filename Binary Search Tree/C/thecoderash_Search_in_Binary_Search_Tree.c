#include <stdio.h>
#include <stdlib.h>

// Node structure of the binary tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int data)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int search(node* root, int x)
{
    if(root==NULL)return 0;
    while(root && root->data!=x)
    {
        if(root->data>x)root=root->left;
        else root=root->right;
    }
    if(root)return 1;
    else return 0;
}

int main()
{
    node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(7);

    /* Example of binary search tree
                4
              /   \
             2     6
            / \   /  \
           1   3 5    8
                     /
                    7 
    */
   if(search(root,4))printf("FOUND!");
   else printf("NOT FOUND!");
    return 0;
}
