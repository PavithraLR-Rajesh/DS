//C program implements a singly linked list with three key operations

#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;}*start;
struct node*insert(struct node*start);
struct node*delete(struct node*start);
void display(struct node*start);
int main()
{
	int a,choice;
	do{
		printf("Enter the choice");
		printf("\n 1 for insert\n 2 for delete\n3 for display");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			start=insert(start);
			break;
			case 2:
			start=delete(start);
			break;
			case 3:
			display(start);
			break;
		}
		printf("\nDo you want to continue press 1:");
		scanf("%d",&a);
}while(a==1);
}
struct node*insert(struct node*start){
	struct node*temp;
	struct node*p;
	int item,pos;
	printf("Enter the item");
	scanf("%d",&item);
	printf("Enter the position where you have to insert");
	scanf("%d",&pos);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	if(start==NULL||pos==1)
	{

		temp->link=start;
		start=temp;
		return(start);
	}
	else{
		p=start;
			for(int i=2;i<pos-1&&p->link!=NULL;i++)
			{
				p=p->link;
			}
			if(p==NULL)
			{
				printf("There are lesser elemnts than postion");
				return(start);
			}
			else{
				temp->link=p->link;
				p->link=temp;
				return(start);
			}
	}
	return(start);
}
	struct node*delete(struct node*start){
		struct node*temp;
		struct node*p;
		int ditem;
		printf("Enter the deleted item");
		scanf("%d",&ditem);
		if(start->data==ditem)
		{
			temp=start;
			start=temp->link;
			free(temp);
			return(start);
		}
		else{
			p=start;
			while(p->link!=NULL)
			{
				if(p->link->data==ditem)
				{
					temp=p->link;
					p->link=temp->link;
					free(temp);
					return(start);
				}
				else{
					p=p->link;
			}
		}
		}
		printf("the item not found");
		return(start);
	}
		void display(struct node*start)
		{
			struct node*p;
			if(start==NULL)
			{
				printf("Linked list is empty");
				return;
			}
			
				p=start;
				while(p!=NULL)
				{
					printf("%d\t",p->data);
					p=p->link;
				}
			}
		
		
	
	