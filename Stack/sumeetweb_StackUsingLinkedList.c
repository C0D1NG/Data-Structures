#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *top = NULL;
void push();
void pop();
void display();

main()
{
	int ch;
	while(1)
	{
		printf("\n\tStack\n");
		printf("Press 1 to Push\n");
		printf("Press 2 to Pop\n");
		printf("Press 3 to Display\n");
		printf("Press 4 to EXIT\n");
		printf("Your Choice : ");
		scanf("%d", &ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Choice. Try Again.\n");
		}
	}
}


void push()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter Data : ");
	scanf("%d",&temp->info);

	if(top == NULL)
	{
		top = temp;
		temp->next = NULL;
		top = temp;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
}

void pop()
{
	struct node *temp;
	if(top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

void display()
{
	struct node *temp;
	if(top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack Elements are : \n");
		for(temp = top; temp != NULL; temp = temp->next)
		{
			printf("%d\n",temp->info);
		}
		printf("\n");
	}
}
