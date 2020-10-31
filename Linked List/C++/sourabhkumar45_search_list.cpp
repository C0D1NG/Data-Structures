/* 
   Using singly linked list,Giving user the choice to enter an element
   at last of list or beginning of list,we ask user to search a particular 
   element of integer type
 */
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
node* head =new node();
void insert_front(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->link=head;
    head=temp;
}
void insert_end(int x)
{
  if(head==NULL)
  {
    node* new_node=new node();
    new_node->data=x;
    new_node->link=head;
    head=new_node;
    return;
  }
  node* temp=head;
  while(temp->link!=NULL)
  {
     temp=temp->link;
  }  
  node* new_node=new node();
  new_node->data=x;
  temp->link=new_node;
  new_node->link=NULL;
}
void search(int x)
{
    int flag = 0, index=0;
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            flag = 1;
            break;
        }
        temp = temp->link;
        index++;
    }
    if(flag == 1)
    {
        cout << x <<" found at position " << index+1 << "\n";
    }
    else
    {
        cout<<x<<" is not avialable in the list\n";
    }
    
}

int main()
{
     head = NULL;
     char choice;
     cout<<"1.Insert node at beginning of list\n2.Insert node at end of list\n3.Exit\n";
     while(true)
     {
         cout<<"Enter your choice\n";
         cin>>choice;
         if(choice == '1')
         {
             int data ;
             cout<<"Enter data to Insert\n";
             cin>>data;
             insert_front(data);
         }
         else if(choice == '2')
         {
             int data ;
             cout<<"Enter data to Insert\n";
             cin>>data;
             insert_front(data);
         }
         else
         {
             break;
         }
         
     }
    cout<<"Do you want to search any data in list\nN/Y";
    cin>>choice;
    if(choice == 'Y'|| choice == 'y')
    {
        cout<<"Enter element you want to search";
        int data;
        cin>>data;
        search(data);
    }
    return 0;
}