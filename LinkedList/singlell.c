//SINGLE LINKEDLIST
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	char name[50];
	struct node*link;
}*p,*temp,*start;
struct node*insert(struct node*start);
struct node*delete(struct node*start);
void display(struct node*start);
int main()
{
	int c,a;
	do{
		printf("Enter the choice :\n");
		printf("enter 1 dor insert\n 2 for display");
		scanf("%d",&c);
		switch(c){
			case 1:
			start=insert(start);
			break;
			case 2:
			display(start);
			break;
		}
		printf("Enter 1 for continue:");
	 scanf("%d",&a);
	}while(a==1);
}

struct node*insert(struct node*start){
	int a;
	char hlo[50];
	struct node*temp;
	struct node*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the roll no");
	scanf("%d",&a);
	printf("enter the name");
	scanf("%s",hlo);
	if(start==NULL)
	{
		start=temp;
		temp->data=a;
		strcpy(temp->name,hlo);
		temp->link=NULL;
		return(start);
	}
	else{
		p=start;
		while(p->link!=NULL)	
	    p=p->link;
	temp->data=a;
	strcpy(temp->name,hlo);
	temp->link=NULL;
	p->link=temp;
	}
}
void display(struct node*start){
	p=start;
	while(p!=NULL)
	{ 
printf("%d\t",p->data);
printf("%s\n",p->name);
p=p->link;
	}
}
		
