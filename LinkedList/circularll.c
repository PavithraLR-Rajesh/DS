//CIRCULAR LINKEDLIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
struct node*link;};
struct node*last=NULL;
struct node*insertbeg(struct node*last);
struct node*insertend(struct node*last);
struct node*delete(struct node*last);
struct node*insertbw(struct node*last);
void display(struct node*last);
int main()
{
	int a,choice,b;
	do{
		printf("Enter 1 for insertbeg\nEnter 2 for insertend\nEnter 3 for insertbetw\nEnter 4 for Delete\nEnter 5 for display");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			last=insertbeg(last);
			break;
			case 2:
			last=insertend(last);
			break;
			case 3:
		    last=insertbw(last);
		    break;
		    case 4:
			last=delete(last);
			break;
			case 5:
			display(last);
			break;
		}
		printf("\nDo you want to continue press 1:");
		scanf("%d",&a);
	}while(a==1);
}
struct node*insertbeg(struct node*last){
	struct node*temp;
	int item;
	printf("Enter the item");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
      temp->data=item;
	 if(last==NULL)
	 {
	  
	     last=temp;
	    last->link=last;
	 }
	 else{
		
		 temp->link=last->link;
		 last->link=temp;
	 }
	 return(last);
}
struct node*insertend(struct node*last){
	struct node*temp;
	int item;
	printf("Enter the item");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
if(last==NULL)
	 {
		 last=temp;
		 last->link=last;
		 return(last);
	 }
	 else{
		 temp->link=last->link;
		 last->link=temp;
		 last=temp;
		 return(last);
	 }
}
struct node*insertbw(struct node*last){
	struct node*p;
	struct node*temp;
	int item,sitem;
	printf("Enter the item");
	scanf("%d",&item);
	printf("Enter the search item");
	scanf("%d",&sitem);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	p=last->link;
	do{
		if(p->data==sitem)
		{
			temp->link=p->link;
			p->link=temp;
		if(last->data==sitem)
		last=temp;
	return(last);
		}
			p=p->link;
		}
	while(p!=last->link);
	printf("ITEM NOT FOUND");
	return(last);
}

struct node *delete(struct node *last) {
    struct node *temp;
    struct node *p;
    int ditem;
    printf("Enter the item to be deleted: ");
    scanf("%d", &ditem);
	p=last->link;
    if (last == NULL) {
        printf("List is empty!\n");
        return last;
    }
    if (last->link == last && last->data == ditem) {
        temp = last;
        last = NULL;
        free(temp);
        return last;
    }
    if (p->data == ditem) {
        temp = p;
        last->link = p->link;
        free(temp);
        return last;
    }
    while (p->link != last) {
        if (p->link->data == ditem) {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return last;
        }
        p = p->link;
    }
    if (last->data == ditem) {
        temp = last;
        p->link = last->link;
        last = p;
        free(temp);
        return last;
    }
    printf("THE ITEM NOT FOUND");
    return last;
}

void display(struct node*last){
	struct node*p;
	p=last->link;
	if(last==NULL)
	{
		printf("it is empty");
	}
	else{
		do{
			printf("%d\t",p->data);
			p=p->link;
		}while(p!=last->link);
	}
}
		
		


	
		