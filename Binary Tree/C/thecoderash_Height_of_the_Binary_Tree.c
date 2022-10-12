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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *root, int x)
{
    if (root == NULL)
        return x;
    return max(height(root->left, x + 1), height(root->right, x + 1));
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);

    /* Example tree
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7
                     /
                    8 
    */
    printf("Height of tree = %d\n", height(root, 0));
    return 0;
}
