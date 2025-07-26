//CIRCULARQUEUE
#include<stdio.h>
int q[50];
int count=0;
int rear=-1;
int front=-1;
int size=4;
void insert();
void delete();
void display();
int main()
{
	
	int c,a;
	do{
		printf("Enter the choice :\n");
		printf("Enter 1 for insert\nEnter 2for delete\nEnter 3 for display");
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
		printf("Enter 1 for continue:\n");
	 scanf("%d",&a);
	}while(a==1);
}

void insert()
{
	int a;
	printf("enter the item");
	scanf("%d",&a);
	if((front==0&&rear==size-1)||(front==rear+1))
	{
		printf("queue is full");
		return;
	}
	else {
		if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==size-1)
		{
			rear=0;
		}
		else{
			rear++;
			
		}
		q[rear]=a;
	}
}
	void delete()
	{ int y;
	y=q[front];
		if(front==-1)
		{
			printf("the queue is empty");
			return;
		}
		else{
			if(front==rear)
			{
			front=-1;
			rear=-1;
			}
			else if(front==size-1)
			{
				front=0;
			}
			else{
			front++;}


		}
			
			printf("the deleted elemnt is:%d",y);
	}
	void display()
	{
		int i,j;
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",q[i]);
			}
		}
		else{
			for(i=0;i<=rear;i++)
			{
				printf("%d\t",q[i]);
			}
			for(i=front;i<size;i++)
			{
				printf("%d\t",q[i]);
			}
		}
		
			
	}