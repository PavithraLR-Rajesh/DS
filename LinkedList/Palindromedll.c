//This C program checks whether a given string is a palindrome using a doubly linked list.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct node{
	char data;
	struct node*next;
	struct node*prev;
}*start,*p,*temp;
struct node*insert(struct node*start,char a);
int ispali(struct node*start);
void display(struct node*start);
int main()
{ int a;
	char name[50];
	int i;
	printf("ENTER A NAME");
	scanf("%s",name);
	for(i=0;i<strlen(name);i++)
	{
		start=insert(start,name[i]);	
}
display(start);
a=ispali(start);
if(a==1)
{	printf("\nIT IS A PALINDROME");
}
else{
printf("\nIT NOT A PALINDROME");
}
}
struct node*insert(struct node*start,char a){
	struct node*temp;
	struct node*p;
	p=start;
	temp=(struct node*)malloc(sizeof(struct node));
if(start==NULL)
{ 
temp->data=a;
temp->next=NULL;
temp->prev=NULL;
start=temp;
return(start);
}
else{
	while(p->next!=NULL)
	{
		p=p->next;
	}
	temp->data=a;
	temp->prev=p;
	temp->next=NULL;
	p->next=temp;
	return(start);
}
}
void display(struct node*start){
	p=start;
	if(start==NULL)
	{
		printf("it is empty");
		return ;
		
	}
	else{
		while(p!=NULL)
		{
			printf("%c\t",p->data);
			p=p->next;
		}
	}
}
int ispali(struct node*start){
struct node*p1=start;
struct node*p2=start;
while(p2->next!=NULL)
{
p2=p2->next;
}
while(p1!=p2&&p1->prev!=p2)
{
	if(p1->data!=p2->data)
	{
	return 0;}
	p1=p1->next;
	p2=p2->prev;
}
return 1;
	}

