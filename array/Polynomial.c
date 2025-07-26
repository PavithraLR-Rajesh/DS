//polynomial operations using arrays of structures
#include<stdio.h>
struct poly{
	int coeff;
	int expo;
}p[20],p1[20],p2[20],p3[20],p4[20],p5[20];
int readpoly(struct poly p[20]);
void display(struct poly p3[20],int t);
int addpoly(struct poly p1[20],int t1,struct poly p2[20],int t2,struct poly p3[20]);
int mult(struct poly p1[20],int t1,struct poly p2[20],int t2,struct poly p3[20],struct poly p4[20]);
int main()
{
int x,z,s,y,c,e,f;
struct poly p1[20],p2[20],p3[20];
do{
	printf("Enter 1 for polynomial reapresentaion 2 for polynomial addition");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
    x=readpoly(p1);
    display(p1,x);
	break;
	case 2:
   y=readpoly(p2);
   printf("THE FIRST POLYNOMIAL:\n");
   display(p2,y);
   z=readpoly(p3);
   printf("THE FIRST POLYNOMIAL:\n");
   display(p3,z);
   e=addpoly(p2,y,p3,z,p4);
   printf("THE ADIITION OF THE POLNOMIALS ARE:");
   display(p4,e);
    printf("THE MULTIPLICATION OF THE POLNOMIALS ARE:");
   f=mult(p2,y,p3,z,p4,p4);
   display(p4,f);
    break;
	}
printf("\ndo you want continue then press 1:");
scanf("%d",&s);
}while(s==1);
}
int readpoly(struct poly p[20]){
	int n,i;
	printf("enter the number of termns");
	scanf("%d",&n);
	printf("enter the coeff and expo");
	for( i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].coeff,&p[i].expo);
	}
	return(n);
}
void display(struct poly p3[20],int t){
	for(int j=0;j<t-1;j++)
	{
		printf("%d*x^%d+",p3[j].coeff,p3[j].expo);
	}
	printf("%d*x^%d\n",p3[t-1].coeff,p3[t-1].expo);
}
int addpoly(struct poly p1[20],int t1,struct poly p2[20],int t2,struct poly p3[20]){
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<t1&&j<t2)
		
		{
			if(p1[i].expo==p2[j].expo)
			{
				p3[k].expo=p1[i].expo;
				p3[k].coeff=p1[i].coeff+p2[j].coeff;
				k++;
				i++;
				j++;
			}
			else if(p1[i].expo>p2[j].expo)
			{
				p3[k].expo=p1[i].expo;
				p3[k].coeff=p1[i].coeff;
				k++;
				i++;
			}
			else{
				p3[k].expo=p2[j].expo;
				p3[k].coeff=p2[j].coeff;
				k++;
				j++;
			}
		}
		while(i<t1)
		{
			    p3[k].expo=p1[i].expo;
				p3[k].coeff=p1[i].coeff;
				k++;
				i++;
				
				
		}
		while(j<t2)
		{
			                p3[k].expo=p2[j].expo;
            				p3[k].coeff=p2[j].coeff;
            				k++;
            				j++;
		}
		return(k);
}
int mult(struct poly p1[20],int t1,struct poly p2[20],int t2,struct poly p3[20],struct poly p4[20]){
	int k=0;
	int i,j;
	for(i=0;i<t1;i++)
	{
		for(j=0;j<t2;j++)
		{
			p3[k].expo=p1[i].expo+p2[j].expo;
			p3[k].coeff=p1[i].coeff*p2[j].coeff;
			k++;
		}
	}
	int sum=0;
	int p=0;
	for(i=0;i<k;i++)
	{
		sum=p3[i].coeff;
		for(j=i+1;j<k;j++)
		{
			if(p2[i].expo==p3[j].expo)
			{
				sum=sum+p3[j].coeff;
				p3[j].coeff=0;
			}
		}
		if(p3[i].coeff!=0)
		{
			p4[p].coeff=sum;
			p4[p].expo=p3[i].expo;
		p++;
		}
	}
	return p;
}
	