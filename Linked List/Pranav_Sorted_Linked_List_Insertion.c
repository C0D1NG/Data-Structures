#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *list, int value)
{

    struct node *help_ptr;
    help_ptr = NULL;
    help_ptr = list;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (list == NULL || list->data > value)
    {
        newnode->next = list;
        list = newnode;
        return list;
    }

    while (help_ptr->next != NULL && help_ptr->next->data < value)
        help_ptr = help_ptr->next;

    newnode->next = help_ptr->next;
    help_ptr->next = newnode;
    return list;
}

void display(struct node *list)
{
    struct node *help_ptr;
    help_ptr = NULL;
    help_ptr = list;

    if (help_ptr == NULL)
        printf("List is Empty\n");

    while (help_ptr != NULL)
    {
        printf("%4d", help_ptr->data);
        help_ptr = help_ptr->next;
    }
}

struct node *delete (struct node *list, int target)
{
    struct node *help_ptr, *node2delete;
    help_ptr = NULL;
    help_ptr = list;
    if (help_ptr == NULL)
    {
        printf("List is Empty\n");
    }
    if (help_ptr != NULL)
    {
        if (help_ptr->data == target)
        {
            list = help_ptr->next;
            printf("%d Deleted\n", target);
            free(help_ptr);
            return list;
        }
        while (help_ptr->next != NULL)
        {
            node2delete = NULL;
            if (help_ptr->next->data == target)
            {
                node2delete = help_ptr->next;
                help_ptr->next = help_ptr->next->next;
                printf("%d Deleted\n", target);
                free(node2delete);
                return list;
            }
            help_ptr = help_ptr->next;
        }
        printf("Element not Found\n");
        return list;
    }
}

void main()
{
    int choice;
    struct node *prev, *head, *p;
    int number = 0;
    struct node *list = NULL;

    while (choice != 4)
    {
        printf("\nEnter the option between 1,2 and 3 to choose a Linked List Function to be executed\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("4: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Insert function is chosen\n");
            number = 0;
            printf("Enter data for the node ");
            scanf("%d", &number);
            if (number != -1)
                list = insert(list, number);
            break;

        case 2:
            printf("Delete function is chosen\n");
            number = 0;
            printf("Enter the data you wish to Delete: ");
            scanf("%d", &number);
            if (number != -1)
                list = delete (list, number);
            break;

        case 3:
            printf("Display function is chosen\n");
            display(list);
            break;

        case 4:
            printf("Exiting the Program\n");
            break;

        default:
            printf("Invalid option\n");
            break;
        }
    }
}
