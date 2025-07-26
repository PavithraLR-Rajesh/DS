
//PROGRAM FOR MERGING TWO SORTED LIST 
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
}*start1=NULL,*start2=NULL,*p1,*p2,*start3,*p;
struct node*merge(struct node*start1,struct node*start2);
struct node *sort(struct node *start, int item) ;
struct node* insertend(struct node* start);
void display(struct node*start);
int main() 
{   int a;
    printf("FIRST LIST\n");
    start1 = insertend(start1);
	display(start1);
	printf("SECOND LIST\n ");
    start2 = insertend(start2);
	display(start2);
    printf("THE MERGED list is:\n");
    start3 = merge(start1, start2);
    display(start3);
    return 0;
}

struct node*merge(struct node*start1,struct node*start2)
{
	p1=start1;
	p2=start2;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<p2->data)
		{
			start3=sort(start3,p1->data);
			p1=p1->link;
		}
		else if(p1->data>p2->data)
		{
			start3=sort(start3,p2->data);
			p2=p2->link;
		}
		else
		{
			start3=sort(start3,p2->data);
		      p1=p1->link;
			  p2=p2->link;
		}
	}
	while(p1!=NULL)
	{ 
           start3=sort(start3,p1->data);
	p1=p1->link;}
	while(p2!=NULL)
	{ 
			start3=sort(start3,p2->data);
			p2=p2->link;
	}
	return(start3);
}

void display(struct node*start)
{  
if(start==NULL)
{
	printf("Linked list is empty");
	return;
}
else{
	p=start;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->link;
	}
}
}
struct node* sort(struct node* start, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Unable to allocate memory.");
        return NULL;
    } else {
        temp->data = item;
        temp->link = NULL;

        if (start == NULL || start->data > item) {
            temp->link = start;
            start = temp;
        } else {
            struct node* p = start;
            while (p->link != NULL && p->link->data < item)
                p = p->link;
            temp->link = p->link;
            p->link = temp;
        }
        return start;
    }
}
struct node* insertend(struct node* start) {
    int data;
    int c;

    do {
        printf("Enter the item");
        scanf("%d", &data);
        start = sort(start,data);
        printf("Do you want to insert another item then press 1\n");
        scanf("%d", &c);
    } while (c== 1);

    return start;
}
