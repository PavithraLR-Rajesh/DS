
//PROGRAM FOR IMPLEMENTING QUEUE USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
int item;
int y;
struct node{
	int data;
	struct node*link;
}*p,*temp,*rear=NULL,*front=NULL;
struct node*insert(struct node*rear);
struct node*delete(struct node*front);
void display();

int main()
{
	int choice,a;
do{
printf("Enter 1 for insert\n");
printf("Enter 2 for delete\n");
printf("Enter 3 for display\n");
printf("Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
rear=insert(rear);
break;
case 2:
front=delete(front);
break;
case 3:
display();;
break;
}
printf("\ndo you want to continue if yes press 1 if no press 0:\n");
scanf("%d",&a);}
while(a==1);
}
struct node*insert(struct node*rear)
{ printf("enter the item");
scanf("%d",&item);

	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficent space");
		return NULL;
	}
temp->data=item;
temp->link=NULL;
if(front==NULL&&rear==NULL)
{ front=temp;
}
else{
rear->link=temp;}
rear=temp;
return(rear);
}
struct node*delete(struct node*front)
{
	if(front==NULL)
	{
		printf("Qeue is empty");
		return NULL;
	}
	y=front->data;
	printf("The deleted item is %d",y);
	if(front==rear)
	{  
    temp=front;
    front=NULL;
	rear=NULL;
	free(temp);
	return(front);
	}
	else{
		temp=front;
		front=front->link;
		free(temp);
		return(front);
	}
}
void display()
{
if(front==NULL&&rear==NULL)
{
	printf("Queue is empty");
	return;
}
p=front;
while(p!=rear)
{
	printf("%d\n",p->data);
	p=p->link;
}
printf("%d",p->data);
}


	