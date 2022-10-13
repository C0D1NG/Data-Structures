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

int isPalindrome(node *head)
{
    if(head==NULL)return 1;
    node *slow = head, *fast = head, *prev, *temp;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    prev = slow, slow = slow->next, prev->next = NULL;
    while (slow)
        temp = slow->next, slow->next = prev, prev = slow, slow = temp;
    fast = head, slow = prev;
    while (slow)
        if (fast->val != slow->val)
            return 0;
        else
            fast = fast->next, slow = slow->next;
    return 1;
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
    printNodes(root);
    if (isPalindrome(root))
        printf("YES this linked list is a Palindrome!");
    else
        printf("NO this linked list is not a Palindrome");
    return 0;
}
