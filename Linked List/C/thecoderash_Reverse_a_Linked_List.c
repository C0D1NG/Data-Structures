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

node *reverseList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *prev = head;
    node *curr = prev->next;
    head->next = NULL;
    while (prev != NULL && curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    node *root = NULL;
    int n, x;
    printf("Enter the number of elements in the Linked list: ");
    scanf("%d", &n);
    printf("Enter the %d elements seperated with spaces: ", n);
    while (n--)
    {
        scanf("%d", &x);
        root = addNode(root, x);
    }
    printf("Before reversing ");
    printNodes(root);
    root = reverseList(root);
    printf("After reversing ");
    printNodes(root);
    return 0;
}
