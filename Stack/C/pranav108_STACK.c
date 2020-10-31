#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;
void push(int item )
{
    if(isFull( )){
       printf("\nStack is overflow");
    }
    else{
        top++;
        stack[top] = item;
        printf("\n%d is pushed", item);
    }
};
///////////////////////////////////////////////
void pop( )
{
    int d;
    if(isEmpty( )){
         printf("\nStack is underflow");
    }
    else{
         printf("\n%d is popped out", stack[top]);
         top--;
    }
}
/////////////////////////////////////////////////////
int isFull( )
{
    if(top == N - 1){
        return 1;
    }
    else{
        return 0;
    }
}
//////////////////////////////////////////////////////
int isEmpty( )
{
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
////////////////////////////////////////////////////////
void display( )
{
    int i;
    if(isEmpty( )){
       printf("\nstack is underflow");
    }
    else{
        printf("\nThe elements of the stack is: ");
        for(i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
    }
}
//////////////////////////////////////////////////////////
int main( )
{
    int choice, item, t, k, y, z;
    printf("\nEnter 1 to push data: ");
    printf("\nEnter 2 to pop data: ");
    printf("\nEnter 3 to display elements: ");
     printf("\nEnter 4 to exit: ");
     while(1)
     {
         printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
         switch(choice)
     {
        case 1:
            printf("\nEnter your data: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
           pop( );
           break;
        case 3:
            display( );
            break;
        case 4:
            exit(0);
        default:
            printf("\ninvalid");
     }
    }
    return 0;
}

