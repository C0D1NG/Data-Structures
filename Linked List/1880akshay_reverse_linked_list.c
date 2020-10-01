#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

//fn to count Node from list

int count()
{
    Node*a=head;
    int cnt=0;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}

void insertEnd(int x) {
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new->data = x;
    new->next = NULL;
    struct Node* temp = head;
    if(head == NULL) {
        head = new;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void print() {
    struct Node* temp = head;
    printf("The list is:");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct Node *current, *prev, *next;
    prev = NULL;
    current = head;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        insertEnd(x);
    }
    printf("\nNode Count:%d",count());
    printf("Original list: ");
    print();
    reverse();
    printf("Reversing...\n");
    printf("Reversed list: ");
    print();
    return 0;
}
