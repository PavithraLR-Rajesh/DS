//Binary Search Tree (BST) to store phone numbers and names, with operations for insertion, deletion (with all 3 cases), searching, and in-order traversal.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	char name[50];
	struct node*lchild;
	struct node*rchild;
}*root=NULL,*ptr,*par;
struct node*insert(struct node*root,int key,char keya[50]);
struct node*delete(struct node*root,int dkey);
struct node*casea(struct node*root,struct node*par,struct node*ptr);
struct node*caseb(struct node*root,struct node*par,struct node*ptr);
struct node*casec(struct node*root,struct node*par,struct node*ptr);
struct node*serach(struct node*ptr,int skey);
void inorder(struct node*ptr);
int main()
{
	int a,c;
	int item;
	char hlo[50];
	int ditem,sitem;
	do{
	printf("Enter 1 for insert\n 2 for delete\n3 for display\n 4 for serching");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
		printf("Enter the phone number");
		scanf("%d",&item);
		printf("Enter the name:");
		scanf("%s",hlo);
		root=insert(root,item,hlo);
		break;
		case 2:
		printf("Enter the deleted phoneno");
		scanf("%d",&ditem);
		root=delete(root,ditem);
		break;
		case 3:
		inorder(root);
		break;
		case 4:
		printf("Enter the item to be serarch");
		scanf("%d",&sitem);
		if(serach(root,sitem)==NULL)
		{printf("KEY NOT FOUND");}
		else
		{printf("FOUND");}
		break;
	}
	printf("\ndo you want to continue press 1:");
	scanf("%d",&a);
	}while(a==1);
}
struct node*insert(struct node*root,int key,char keya[50]){
	struct node*ptr,*par;
	ptr=root;
	par=NULL;
	while(ptr!=NULL)
	{
		par=ptr;
		if(key<ptr->data)
		{
			ptr=ptr->lchild;
		}
		else if(key>ptr->data)
		{
			ptr=ptr->rchild;
		}
		else{
			printf("Duplicate key");
			return(root);
		}
		
	}
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	strcpy(temp->name,keya);
temp->lchild=NULL;
temp->rchild=NULL;
if(par==NULL)
{
	root=temp;
}
else if(key<par->data)
{
	par->lchild=temp;
}
else{
	par->rchild=temp;
}
return(root);
}
struct node*casea(struct node*root,struct node*par,struct node*ptr)
{
	if(par==NULL)
	{
		root=NULL;
	}
	else if(ptr==par->lchild)
	{
		par->lchild=NULL;
	}
	else{
		par->rchild=NULL;
	}
	free(ptr);
	return(root);
}
struct node*caseb(struct node*root,struct node*par,struct node*ptr){
	struct node*child;
	if(ptr->lchild!=NULL)
	child=ptr->lchild;
else
	child=ptr->rchild;

if(par==NULL)
	root=child;
else if(ptr==par->lchild)
	par->lchild=child;
else
	par->rchild=child;
free(ptr);
return(root);
}
struct node*casec(struct node*root,struct node*par,struct node*ptr){
	struct node*parsucc,*succ;
	parsucc=ptr;
	succ=ptr->rchild;
	while(succ->lchild!=NULL)
	{
		parsucc=succ;
		succ=succ->lchild;
	}
	ptr->data=succ->data;
	strcpy(ptr->name,succ->name);
	if(succ->lchild==NULL&&succ->rchild==NULL)
	{
		root=casea(root,parsucc,succ);
	}
	else{
		root=caseb(root,parsucc,succ);
	}
	return(root);
}
struct node*delete(struct node*root,int dkey){
	struct node*ptr,*par;
	ptr=root;
	par=NULL;
	while(ptr!=NULL)
	{
if(dkey==ptr->data)
break;
 par=ptr;
 if(dkey<ptr->data)
	  ptr=ptr->lchild;
  else
   ptr=ptr->rchild;
	}
  if(ptr==NULL)
  {
	  printf("DELETE KEY NOT FOUND");
  }
  else{
	  if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
		  root=casec(root,par,ptr);
	  else if(ptr->lchild!=NULL)
		 root=caseb(root,par,ptr);
	 else if(ptr->rchild!=NULL)
		 root=caseb(root,par,ptr);
	 else
		 root=casea(root,par,ptr);
  }
  return root;
}
void inorder(struct node*ptr){
	if(ptr==NULL)
	{
		return;  //empty
	}
	else{
		inorder(ptr->lchild);
		printf("%d\t",ptr->data);
		printf("%s\t",ptr->name);
		inorder(ptr->rchild);
	}
}
struct node*serach(struct node*ptr,int skey){
	if(ptr==NULL)
	{
	return NULL;}
	else if(skey<ptr->data)
	{  
 return (serach(ptr->lchild,skey));
	}
	else if(skey>ptr->data){
		return(serach(ptr->rchild,skey));
	}
	else{
	return ptr;
}
}
	 

	  