#include <stdio.h>
#include <stdlib.h>

struct c_queue
{
    int element;
    struct c_queue *next;  //Pointing to next queue element
};

struct c_queue *front = NULL, *rear = NULL;

void enqueue(int val)  //Insert/Enqeue an element
{
    struct c_queue *ptr = (struct c_queue*)malloc(sizeof(struct c_queue));
    ptr->element = val;

    if (front == NULL)
        front = ptr;
    else
        rear->next = ptr;

    rear = ptr;
    rear->next = front;
}

int dequeue() //Remove an element
{
    if (front == NULL) //if queue is empty
        return -1;

    int val;

    if (first == rear) //If it is the last element to dequeue
    {
        val = front->element;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct c_queue *temp = front;
        val = front->element;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    
    return val;   
}

void display()
{
    struct c_queue *ptr = front;

    if (front == NULL)
    {
        printf("Circular Queue is empty");
        return;
    }

    while (ptr->next != front)
    {
        printf("%d -> ", ptr->element);
        ptr = ptr->next;
    }
    printf("%d", ptr->element);
}

int main()
{
    int num1, num2, choice;

    while (choice != 4)
    {
        printf("\n\n**********MENU**********");
        printf("\n1) Enqueue an element.");
        printf("\n1) Denqueue an element.");
        printf("\n1) Display all elements.");
        printf("\n1) Exit.");
        printf("\n\nEnter a choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1: printf("\nEnter the element to enqueue");
                scanf("%d", &num1);
                enqueue(num1);
                break;

        case 2: num2 = dequeue();
                if (num2<0)
                    printf("\nCircular Queue is Empty");
                else
                    printf("\n%d dequeued from the queue.", num2);
                break;

        case 3: display();
                break;

        case 4: break;
        
        default: printf("\nInvalid input, please try again.\n");
        }
    }
    return 0;
}