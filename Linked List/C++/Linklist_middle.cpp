#include<stdio.h>
#include<stdlib.h>
struct linked{
	int data;
	 struct linked *next;
};
typedef struct linked l;
l *start ,*node,*temp;
void traversal()
{	l *s=start;
		printf("\nList is: ");
	while(s!=NULL)
	{
		printf("%d  ",s->data);
		s=s->next;
		
	}
	printf("\n");
}
void insert_begn(int newdata){
	node=(l*)malloc(sizeof(l));
	node->data=newdata;
	node->next=start;
	start=node;
}
void insert_end(int newdata)
{
	l *p=start;
	node=(l*)malloc(sizeof(l));
	node->data=newdata;
	node->next=NULL;
	while(p->next!=NULL)
	p=p->next;
	p->next=node;
}
void insert_loc(int newdata,int loc)
{int k;
l * p;
node=(l*)malloc(sizeof(l));
node->data=newdata;
p=start;
if(loc==1){
	node->next=start->next;
	start=node;
}
else{
for(k=1;k<loc-1;k++)
{
  p=p->next;
}}
if(p==NULL)
{printf("location not found");
exit(0);}
node->next=p->next;
p->next=node;
}

void delete_begn()
{ l * p;
p=start;
if(start->next==NULL)
{
p=start;
start=NULL;
free(p);
}
else
{
  temp=start;
  start=temp->next;
  free(temp);
}
}

void delete_end()
{l * p;
p=start;
if(start->next==NULL)
{
p=start;
start=NULL;
free(p);
}
else{
      while(p->next!=NULL)
        {  temp=p;
            p=p->next;
          }
         temp->next=NULL;
         free(p);
    }

}
void delete_this(int newdata)
{l * p;
p=start;
temp=p;
if(p->data==newdata)
{
  p=temp->next;
  start=p;
  free(temp);
}
else
{
  while(temp!=NULL && temp->data!=newdata)
  {
    p=temp;
    temp=temp->next;
  }
  if(temp->data==newdata)
  {
   p->next=temp->next;
   free(temp);
  }
  else
  {
    printf("data not found");
  }
  
}

	
}
void middle(){
	node=start;
	temp=start;
	while(temp!=NULL && temp->next!=NULL){
		temp=temp->next->next;
		node=node->next;
	}
	printf("%d",node->data);
}

int main(){
int k,r;
start=NULL;
printf("options:1 for traversal\n2 for insert at begin\n3 for insert at end\n4 for insert at given location\n5 for delete at begin\n6 for delete at end\n7 for delete given data\n8 for middle element\n9  for exit\n");
printf("_______________\n");
int op;
do{scanf("%d",&op);
switch(op)
{
case 1:
	traversal();
		break;
case 2:
	scanf("%d",&k);
	insert_begn(k);
	traversal();
		break;
case 3:
	scanf("%d",&k);
	insert_end(k);
	traversal();
		break;
case 4:
	scanf("%d %d",&k,&r);
	insert_loc(k,r);
	traversal();
		break;
case 5:
	delete_begn();
	traversal();
		break;
case 6:
	delete_end();
	traversal();
		break;
case 7:
	scanf("%d",&k);
	delete_this(k);
	traversal();
		break;
case 8:
	middle();

		break;
	
}
}while(op!=9);
return 0;
}

