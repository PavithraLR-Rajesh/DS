//sorted linked list of strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data[50];
struct node*link;}*start;
struct node*insert(struct node*start);
struct node*delete(struct node*start);
void display(struct node*start);
int main()
{
	int choice,a;
	do{
		printf("Enter the 1 for insert in sorted lnked list\n");
		printf("Enter 2 for display");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			start=insert(start);
			break;
			case 2:
			display(start);
			break;
		
		}
	   printf("\ndo u want to continue press 1:");
		scanf("%d",&a);
		}while(a==1);
}
struct node*insert(struct node*start){
	struct node*temp;
	struct node*p;
	char item[50];
	p=start;
	printf("Enter the item");
	scanf("%s",item);
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->data,item);
	if(start==NULL||start->data>item)
	{
		temp->link=start;
		start=temp;
		return(start);
	}
	else{
		while(p->link!=NULL&&strcmp(p->link->data,item)<0)
		{p=p->link;
		}
		temp->link=p->link;
		p->link=temp;
		return start;
	}
}
void display(struct node*start)
{
	struct node*p;
	p=start;
	while(p!=NULL)
	{
		printf("%s\t",p->data);
		p=p->link;
	}
}