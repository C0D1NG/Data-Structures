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

void bfs(struct node *root)
{
    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        struct node *temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
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
    printf("BFS traversal: ");
    bfs(root);
    return 0;
}