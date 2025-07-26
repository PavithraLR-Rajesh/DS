//TWO STACK IN SAME ARRAY
#include<stdio.h>
#include<stdlib.h>
#define size 4
int stack[size];
void pusha();
void pushb();
int topa=-1;
int topb=size;
void popa();
void popb();
void displaya();
void displayb();
int main()
{
	int a,b;
	do{
		printf("enter 1,2,3 for stack A\n");
		printf("1-push\n2-pop\n3-display\n");
		printf("enter 4,5,6 for stack B\n");
		printf("4-push\n5-pop\n6-display");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			pusha();
			break;
			case 2:
			popa();
			break;
			case 3:
			displaya();
			break;
			case 4:
			pushb();
			break;
			case 5:
			popa();
			break;
			case 6:
			displayb();
		break;}
		printf("\n enter 1 to continue :");
     	scanf("%d",&b);
	}
while(b==1);
}
void pusha(){
	int y;
	printf("Enter a item");
	scanf("%d",&y);
	if(topa==topb-1)
	{
		printf("stack overflow");
	}
	else{
		topa++;
		stack[topa]=y;
	}
}
void popa()
{
	int y;
	if(topa==-1)
	{ printf("Stack is underflow");
return;
	}
	else{
		y=stack[topa];
		topa--;
	}
	printf("The deleted element is :%d",y);
}
void pushb()
{ int a;
printf("Enter the item:");
scanf("%d",&a);
	if(topb-1==topa)  //because topb=size 
	{
		printf("stack overflow");
	}
	else{
		topb--;
		stack[topb]=a;
	}
}
void popb()
{
	int y;
	if(topb==size)
	{ printf("Stsck is underflow");
return;
	}
	else{
		y=stack[topa];
		topb++;
		
	}
	printf("The deleted element is :%d",y);
}
void displaya(){
	if(topa==-1)
	{
		printf("stack is empty");
	}
	else
	{
		for(int i=topa;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
	}
	
}
void displayb()
{
	if(topb==size)
	{
		printf("stack is underflow");
	}
     else{
		for(int j=topb;j<size;j++)
		{
			printf("\n%d\t",stack[j]);
		}
	}
}

			
		
	
