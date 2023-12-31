/*
Name: Sanchita Warade
Roll No: 61
Branch: IT
Batch: C*/

#include <stdio.h>
# include <stdlib.h>

struct node
{
int info;
struct node* next;
};

struct node *front,*rear;

void init()  // initialization
{
front=rear=NULL;
}

struct node* getnode (void)
{
return  (( struct node* ) malloc (sizeof(struct node)));
}

void freenode(struct node *p)
{
free(p);
}

int empty()
{
 if(rear==NULL)
    return 1;
 else
    return 0;
}

void enqueue(int t)  // inserting element in the queue
{
struct node *newnode;
newnode=getnode();
newnode->info=t;

if(empty())                     //If queue is already empty
 {
      newnode->next=NULL;   
 	  front=newnode;
      rear=newnode;
 }
else									// Queue has elements
 { 
      newnode->next=rear->next;
	  rear->next=newnode;
	  rear=newnode;
 }
}

int dequeue()    //deleting the element
{
int x;
struct node* temp;
temp=front;
x=front->info;
if(front==rear)                  // If queue has single element
  {
     init();
  }	
else                                           
  {
 front=front->next;
  }
freenode(temp);
return x;
}

void display()  //displaying the queue
{
struct node *temp;

if(empty())
  printf("\n Queue is empty");
else
  {
	temp=front;
        while(temp!=NULL)
          {
             printf("-> %d ",temp->info);
             temp=temp->next;
          }
	
  }
}

void main()
{
int x, i, ch,ans;
init();
do
{
//clrscr();
printf("\n Operation on Queue");
printf("\n1. Enqueue");
printf("\n2. Dequeue");
printf("\n3. Display");
printf("\n4. Exit");
printf("\n Enter your choice:");
scanf("%d",&ch);

switch(ch)
{
case 1: printf("\n Enter the value to be inserted :");
        scanf("%d",&x);
        enqueue(x);
        break;
case 2: if(!empty())
    {
	    x=dequeue();
        printf("\n %d is deleted",x);
	}
 	else
	{
	    printf("\n Queue is empty");
	}
	break;
case 3:display();
       break;
case 4: exit(1);
        break;
default: printf("\n Wrong Choice");
         break;
}
printf("\nDo you want to continue? (Press 1=yes, 0=no)");
scanf("%d",&ans);
}while(ans==1);
}
