#include <stdio.h>
#include <stdlib.h>
 
struct node {
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
 
    return (node);
}
 
int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
 
        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);
    }
}
 
int main()
{
    struct node* root = newNode(7);
 
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->left->left->right = newNode(10);

    printf("Height of tree is %d", maxDepth(root));
 
    getchar();
    return 0;
}
