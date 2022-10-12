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

node *insertIntoSortedLL(node *root, int x)
{
    node *head = root;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = x;
    newNode->next = NULL;
    if (root == NULL)
        return newNode;
    if (root->val > x)
    {
        newNode->next = head;
        return newNode;
    }
    while (root->next != NULL && root->next->val < x)
        root = root->next;
    if (root->next == NULL)
    {
        root->next = newNode;
    }
    else
    {
        newNode->next = root->next;
        root->next = newNode;
    }
    return head;
}

int main()
{
    node *root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 20);
    root = addNode(root, 30);
    root = addNode(root, 40);
    root = addNode(root, 50);
    printNodes(root);
    printf("Enter Element to be inserted in the above Linked List: ");
    int x;
    scanf("%d", &x);
    root = insertIntoSortedLL(root, x);
    printf("\nAfter insertion");
    printNodes(root);
    return 0;
}
