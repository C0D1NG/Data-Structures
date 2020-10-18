// Program in C++ to find middle node of the Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node//declaring the structure 
{
    int value;
    struct Node* next;
    Node(int x){
        value = x;
        next = NULL;
    }
};

void print(Node* node)//printing the linked list
{
    while(node != NULL){
        cout<< node->value << " ";
        node = node->next;
    }
    cout<<"\n";
}

//function to find the middle element of the linked list
int middleElement(Node *head)
{
    Node* fastptr = head;
    Node* slowptr = head;

    while(fastptr != NULL and fastptr->next != NULL){
        fastptr = fastptr->next->next;//to move the it 2 times fast
        slowptr = slowptr->next;//it will be halfway there of the linked list
    }
    return slowptr->value;//the value of slowptr is the middle element
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for(int i=0;i<t-1;++i){
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<middleElement(head)<<endl;
    }
    return 0;
}


