#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int item;
    struct node *left;
    struct node *right;
 
} Node;
 
void DFS(Node *root)
{
    if (root)
    {
        if (root->left)
            DFS(root->left);
 
        if (root->right)
            DFS(root->right);
 
        printf("%d  ", root->item);
    }
}

void AddNode(Node **root, int item)
{
    Node *temp = *root;
    Node *prev = *root;
 
    if (*root == NULL)
    {
        *root = (Node *)malloc(sizeof(Node));
 
        (*root)->item = item;
        (*root)->left = (*root)->right = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (item > temp->item)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (Node *)malloc(sizeof(Node));
        temp->item = item;
 
        if (item >= prev->item)
            prev->right = temp;
        else
            prev->left = temp;
    }
}

int main()
{
    struct node *head = NULL;
    AddNode(&head, 11);
    AddNode(&head, 33);
    AddNode(&head, 45);
    AddNode(&head, 88);
    AddNode(&head, 7);
 
    DFS(head);
    printf("\n");
 
    return 0;
}
