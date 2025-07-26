//Linear Stack
#include<stdio.h>
int std[10];
int size=3;
int top=-1;
void push();
void pop();
void isempty();
void isfull();
void peek();
void display();
int main()
{
	int choice,a;
	do{
		printf("Enter the 1 for push\n 2 for pop\n 3 for isempty");
		printf("\n 4 for isfull\n 5 for peek operation\n6 for display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			isempty();
			break;
			case 4:
			isfull();
			break;
			case 5:
			peek();
			break;
			case 6:
			display();
			break;
		}
		
printf("\ndo you want to continue press 1:");
scanf("%d",&a);
	}while(a==1);	
}
void push()
{
	int item;
	printf("Enter item");
	scanf("%d",&item);
	if(top==size-1)
	{
		printf("stack is full");
		return;
	}
	else{
		top++;
		std[top]=item;
	}
}
void pop()
{
	int y;
	if(top==-1)
	{
		printf("stack is empty");
		return;
	}
	else{
		y=std[top];
	top--;}
	printf("the deleted item is %d",y);
}
void isempty()
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else{
		printf("stack is not  empty");
	}
}
	void isfull()
	{
		if(top==size-1)
		{
			printf("stack is full\n");
		}
		else{
			printf("stack is not full");
		}
	}
	void peek()
	{
		printf("The top elemnt is %d",std[top]);
	}
	void display()
	{
		int i;
		for(i=0;i<=top;i++)
		{
			printf("%d\t",std[i]);
		}
	}
			
	
		