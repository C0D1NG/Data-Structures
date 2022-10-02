#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

// Node structure of the binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int maxNode(struct node *root)
{
    if (root == NULL)
        return 0;
    int leftSum = maxNode(root->left);
    int rightSum = maxNode(root->right);
    return max(root->data, max(leftSum, rightSum));
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    /* Example tree
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7
    */

    printf("Max node in binary tree = %d\n", maxNode(root));
    return 0;
}
