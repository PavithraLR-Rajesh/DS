
//PROGRAM FOR IMPLEMENTING STACK USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
int item;
int y;
struct node{
	int data;
	struct node*link;
}*p,*temp,*top;
struct node*push(struct node*top);
struct node*pop(struct node*top);
void display();

int main()
{
	int choice,a;
do{
printf("Enter 1 for push\n");
printf("Enter 2 for pop\n");
printf("Enter 3 for display\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
top=push(top);
break;
case 2:
 top=pop(top);
break;
case 3:
display();;
break;
}
printf("\ndo you want to continue if yes press 1 if no press 0:\n");
scanf("%d",&a);}
while(a==1);
}

struct node*push(struct node*top)
{
printf("enter the item");
scanf("%d",&item);
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
	printf("insufficent space");
	return NULL;
}
temp->data=item;
temp->link=top;
top=temp;
return(top);
}
struct node*pop(struct node*top)
{

if(top==NULL)
{
	printf("stack is empty");
	return NULL;
}
else{
	temp=top;
	y=temp->data;
	printf("the deleted item is %d",y);
	top=top->link;
	free(temp);
	return(top);
}
}
void display()
{
	p=top;
	if(top==NULL)
	{
	printf("stack is empty");
	return;
	}
	else{
		while(p!=NULL)
		{
			printf("%d\n",p->data);
			p=p->link;
		}
	}
}
	

	
