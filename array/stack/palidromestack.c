//his C program implements a stack using an array to perform push, pop, display (normal and reverse), and palindrome checking of characters.
#include<stdio.h>
char st[50];
char c[10];
int top=-1;
int size=4;
void push(char item);
char pop();
void display(int d);
void pali();
int main()
{
	char m;
	int c,a,b;
do{
	printf("enter the choice 1 for push\n2 for pop operation\n 3for check palidrome\n 4for display");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
		printf("Enter the character\n");
		scanf(" %c",&m);
		push(m);
		break;
		case 2:
		printf("The poped elemnts is %c",pop());
		break;
		case 3:
		pali();
		break;
		case 4:
		printf("Enter 1 for display stack \n Enter 2 for display reversed stack");
		scanf("%d",&b);
		display(b);
		break;
}
printf("\ndo you want to continue press 1 ");
scanf("%d",&a);}
while(a==1);
}
	
void push(char item )
{
	if(top==size-1){
		printf("Stack is full");
	}
	else{
		
		top++;
		st[top]=item;
	}
	
}
char pop()
{
	
	char y;
	if(top==-1){
		printf("Empty");
		return '\0';
	}
	else{
		
		y=st[top];
		top--;
	}
	return y;
}
void pali(){
	int ispali=0;
	for(int i=0;i<=top;i++){
		c[i]=pop();
	}
	for(int i=0;i<=top;i++){
		
		if(st[i]==c[i])
		{
			
			ispali=1;
			break;
		}
		
}
if(ispali==1)
{
	printf("it is a palidrome");
}
else{
	printf("it is not a palidrome");
}
}
void display(int d)
{
	int i;
	if(d==1)
	for(i=0;i<=top;i++)
	{
		printf("%c\t",st[i]);
	}
	else{
		for(i=top;i>=0;i--)
	{
		printf("%c\t",st[i]);
	}
		
}
}
