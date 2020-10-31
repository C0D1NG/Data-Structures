#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node {
	int data;
	struct Node* next;
};

// Helper function to create a new Node with the given data and
// pushes it onto the front of the list
void push(struct Node** head, int data)
{
	// create a new linked list node from heap
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Iterative function to return K'th node from the end in a linked list
struct Node* getKthFromtheEnd(struct Node* head, int k)
{
	int n = 0;
	struct Node* curr = head;

	// Count number of nodes in the linked list
	while (curr)
	{
		curr = curr->next;
		n++;
	}

	// if number of nodes is more than or equal to K
	if (n >= k)
	{
		// return (n-k+1)th node from the beginning
		curr = head;
		for (int i = 0; i < n - k; i++)
			curr = curr->next;
	}

	return curr;
}

// main method
int main(void)
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(keys) / sizeof(keys[0]);

	struct Node* head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, keys[i]);

	int k = 3;
	struct Node* node = getKthFromtheEnd(head, k);

	if (node)
		printf("K'th node from the end is %d", node->data);

	return 0;
}
// This contribution is done by RaghavKaushal03
