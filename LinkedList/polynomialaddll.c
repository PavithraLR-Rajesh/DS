//POLYNOMIAL ADDITION USING LINKEDLIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int expo;
	struct node*link;
}*start1,*start2,*start3,*p1,*p2,*p3;
struct node*insert(struct node*start,int coeff,int expo);
struct node*readpoly(struct node*start);
struct node*addition(struct node*p1,struct node*p2,struct node*p3);
void display(struct node*start);
int main()
{ 
printf("THE FIRST POLYNOMIAL\n");
	p1=readpoly(start1);
	display(p1);
	printf("THE SECOND POLYNOMIAL\n");
	p2=readpoly(start2);
	display(p2);
	printf("\nTHE ADDITION OF TWO POLYNOMIAL");
	p3=addition(p1,p2,p3);
	display(p3);
	return 0;
	
}
struct node*insert(struct node*start,int coeff,int expo){
	struct node*p;
	struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
	temp->coeff=coeff;
	temp->expo=expo;
	temp->link=NULL;
	if(start==NULL)
	{
	start=temp;
	return(start);
	}
	else{
		p=start;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
		return(start);
}
struct node*readpoly(struct node*start){
	int coe,exp,a;
	do{
		printf("Enter the coeff,expo");
		scanf("%d%d",&coe,&exp);
		start=insert(start,coe,exp);
	printf("\nDo you want to conitinue insert more coeff press  1:");
	scanf("%d",&a);
	}while(a==1);
	return(start);
		
}
struct node*addition(struct node*p1,struct node*p2,struct node*p3){
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->expo>p2->expo)
		{
			p3=insert(p3,p1->coeff,p1->expo);
			p1=p1->link;
		}
		
		else if(p1->expo<p2->expo)
		{
			p3=insert(p3,p2->coeff,p2->expo);
			p2=p2->link;
		}
		else{
			p3=insert(p3,p1->coeff+p2->coeff,p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		p3=insert(p3,p1->coeff,p1->expo);
			p1=p1->link;
	}
	while(p2!=NULL)
	{
		
			p3=insert(p3,p2->coeff,p2->expo);
			p2=p2->link;

	}
	return(p3);
}
void display(struct node*start){
	struct node*p;
		p=start;
		while(p->link!=NULL)
		{
			printf("%d*x^%d+",p->coeff,p->expo);
			p=p->link;
		}
			printf("%d*x^%d",p->coeff,p->expo);
	}

	