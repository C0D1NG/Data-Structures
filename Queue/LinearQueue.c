#include<stdio.h>
#include<stdlib.h>
#define cap 10

int front = 0;
int rear = 0;
int queue[cap];

void add(){
    if (rear == cap){
        printf("Queue is full");
    }
    else{
        int ele;
        printf("\nEnter Element to Add: ");
        scanf(" %d",&ele);
        queue[rear] = ele;
        rear++;
    }
}

void delete(){
    if (front == rear){
        printf("\nQueue is Empty");
    }
    else{
        printf("The Deleted Element is: %d",queue[front]);
        front++;
    }
}

void display(){
    if(rear == front){
        printf("Queue is Empty");
    }
    else{
        printf("Queue: ");
        for (int i=front;i<rear;i++){
            printf("%d  ",queue[i]);
        }
    }
}

int main(){
    int n;
    
    printf("Linear Queue Data Structure\n");
    printf("\nMenu\n");
    printf("1 = Enqueue\n2 = Dequeue\n3 = Display\n4 = Stop Program");
    
    printf("\n \nEnter Appropriate Option: ");
    scanf("%d",&n);
    
    while(1){
        switch(n){
            case (1):add();
            break;
            case (2):delete();
            break;
            case (3):display();
            break;
            case (4):exit(0);
            default:printf("\n\nNo / Incorrect option choosen..!!");break;
        }
        printf("\nMenu\n");
        printf("1 = Enqueue\n2 = Dequeue\n3 = Display\n4 = Stop Program");
        printf("\n \nEnter Appropriate Option: ");
        scanf("%d",&n);
    }
    
return 0;
}