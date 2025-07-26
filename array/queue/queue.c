//simple linear queue
#include<stdio.h>
int rear=-1;
int front=-1;
int q[50];
int size=3;
void insert();
void delete();
void display();
int main()
{
	int c,a;
	do{
		printf("Enter the choice :\n");
		printf("enter 1 dor insert\nenter 2for delete\nenter 3 for display");
		scanf("%d",&c);
		switch(c){
			case 1:
			insert();
			break;
			case 2:
			delete();
			break;
			case 3:
			display();
			break;
		}
		printf("Enter 1 for continue:");
	 scanf("%d",&a);
	}while(a==1);
}
void insert()
{
	int item;
	printf("Enter a item");
	scanf("%d",&item);
	if(rear==size-1)
	{
		printf("queue is full");
		return;
	}
	else if(front==-1&&rear==-1)
	{
		front++;
		rear++;
	}
	else{
		rear++;
	}
	q[rear]=item;
}
void delete()
{
	int y;
		
	y=q[front];
	if(front==-1)
	{
		printf("queue is empty");
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else{
		front++;
	}
  printf("The deleled elemenmt is %d",y);
}
void display()
{
	if(front==-1)
	{
		printf("queue is empty");
	}
	else{
	for(int i=front;i<=rear;i++)
     printf("%d\t",q[i]);
}
}
	
	