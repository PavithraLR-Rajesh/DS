// priority queue using an array
#include<stdio.h>
#include<stdlib.h>
int count=0;
int rear=-1;
int front=-1;
int size=3;
int q[50];
void insert(int data);
void delete();
void display();
int isfull();
void main()
{
	
	
	int c,a,d;
	do{
		printf("Enter the choice :\n");
		printf("Enter 1 dor insert\nEnter 2for delete\nEnter 3 for display");
		scanf("%d",&c);
		switch(c){
			case 1:
			printf("\nEnter the data");
			scanf("%d",&d);
			insert(d);
			break;
			case 2:
			delete();
			break;
			case 3:
			display();
			break;
		}
		printf("\nEnter 1 for continue:");
	 scanf("%d",&a);
	}while(a==1);
}

int isfull()
{
	if(rear==size-1)
	{
		printf("queue is full");
		return 1;
	}
	else
		return 0;
}
void insert(int data)
{
	int i;
	if(isfull()==0)
	{
		if(count==0)
		{
			q[count]=data;
			count++;
			rear++;
			front++;
		}
		else{
			for(i=count-1;i>=0;i--)
			{
				if(data<q[i])
				{
					q[i+1]=q[i];
				}
				else{
					break;
				}
			}
				q[i+1]=data;
				count++;
				rear++;
			}
		}
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
					