#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *makeNewNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorderDfs(struct node *root)
{
    if (root == NULL)
        return;
    inorderDfs(root->left);
    printf("%d ", root->data);
    inorderDfs(root->right);
}

void preorderDfs(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderDfs(root->left);
    preorderDfs(root->right);
}

void postorderDfs(struct node *root)
{
    if (root == NULL)
        return;
    postorderDfs(root->left);
    postorderDfs(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = makeNewNode(1);
    root->left = makeNewNode(2);
    root->right = makeNewNode(3);
    root->left->left = makeNewNode(4);
    root->left->right = makeNewNode(5);
    root->right->left = makeNewNode(6);
    root->right->right = makeNewNode(7);
    /*
    Example tree:
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    printf("\nInorder DFS traversal: ");
    inorderDfs(root);
    printf("\nPreorder DFS traversal: ");
    preorderDfs(root);
    printf("\nPostorder DFS traversal: ");
    postorderDfs(root);
    return 0;
}