#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
int create(struct node **);
int palin_check (struct node *, int);
void release(struct node **);
 
int main()
{
    struct node *p = NULL;
    int result, count;
 
    printf("Enter data into the list\n");
    count = create(&p);
    result = palin_check(p, count);
    if (result == 1)
    {
        printf("The linked list is a palindrome.\n");
    }
    else
    {
        printf("The linked list is not a palindrome.\n");
    }
    release (&p);
 
    return 0;
}
 
int palin_check (struct node *p, int count)
{
    int i = 0, j;
    struct node *front, *rear;
 
    while (i != count / 2)
    {
        front = rear = p;
        for (j = 0; j < i; j++)
        {
            front = front->next;
        }
        for (j = 0; j < count - (i + 1); j++)
        {
            rear = rear->next;
        }
        if (front->num != rear->num)
        {
            return 0;
        }
        else
        {
            i++;
        }
    }
 
    return 1;
}
 
int create (struct node **head)
{
    int c, ch, count = 0;
    struct node *temp;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        count++;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = *head;
        *head = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    }while (ch != 0);
    printf("\n");
 
    return count;
}
 
void release (struct node **head)
{
    struct node *temp = *head;
 
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}