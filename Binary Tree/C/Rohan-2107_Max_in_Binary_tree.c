#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
int Max(struct Node* root)
{
    if (root == NULL)
        return INT_MIN;
 
    int res = root->data;
    int leftres = Max(root->left);
    int rightres = Max(root->right);
    if (leftres > res)
        res = leftres;
    if (rightres > res)
        res = rightres;
    return res;
}

int main(void)
{
    struct Node* NewRoot = NULL;
    struct Node* root = newNode(6);
    root->left = newNode(5);
    root->right = newNode(9);
    root->left->right = newNode(18);
    root->left->right->left = newNode(86);
    root->left->right->right = newNode(99);
    root->right->right = newNode(22);
    root->right->right->left = newNode(41);
 
    printf("Maximum element is %d \n", Max(root));
 
    return 0;
}
