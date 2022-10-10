#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node *addNode(node *root, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    node *head = root;
    if (head == NULL)
        return newNode;
    while (head->next)
        head = head->next;
    head->next = newNode;
    return root;
}

void printNodes(node *root)
{
    printf("Elements in linked list => ");
    while (root)
    {
        printf("%d -> ", root->val);
        root = root->next;
    }
    printf("NULL\n");
}

int findInLinkedList(node *root, int val)
{
    int flag = 0;
    while (root)
    {
        flag |= (root->val == val);
        root = root->next;
    }
    return flag;
}

int main()
{
    node *root = NULL;
    root = addNode(root, 1);
    root = addNode(root, 2);
    root = addNode(root, 3);
    root = addNode(root, 4);
    root = addNode(root, 5);
    printNodes(root);
    int toFind = 4;
    if (findInLinkedList(root, toFind))
        printf("%d is found in the linked list.\n", toFind);
    else
        printf("%d is not found in the linked list.", toFind);
    return 0;
}