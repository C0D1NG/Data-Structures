#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void list(struct node** head, int data)//function to build linked list
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void display(struct node* head)//function to print linked list
{
	struct node* ptr = head;
	while (ptr)
	{
	     printf("%d  ",ptr->data);
		ptr = ptr->next;
	}
}

struct node* newNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertion_sort(struct node** head, struct node* newNode)//function to insert data in sorted position
{
	//If linked list is empty
	if (*head == NULL || (*head)->data >= newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	//Locate the node before insertion
	struct node* current = *head;
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
}

int main(void)//main method
{
    int n,k;
	printf("Enter the size of linked list :\n");
	scanf("%d",&n);
	int data[100];
	printf("Enter linked list data in sorted order :\n");
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&data[i]);
	}
	
	struct node* head = NULL;
    
	//constructing linked list
	for (int i = n-1; i >= 0; i--)
	list(&head, data[i]);
	printf("Linked list before insertion : \n");
    display(head);
    printf("\nEnter data you want to insert: ");
    scanf("%d",&k);
	insertion_sort(&head, newNode(k));
	printf("Linked list after insertion : ");
	display(head);

	return 0;
}
