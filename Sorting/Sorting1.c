//Bubble, Selection, and Insertion Sort are basic sorting algorithms 
#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n);
void bsort();
void ssort();
void isort();

void main(){
int choice;
do{
printf("\nEnter choice:");
printf("\nEnter 1 for bubble sort\nEnter 2 for selection sort");
printf("\nEnter 3 for insertion sort\nEnter 4 for exit:");
scanf("%d",&choice);
switch(choice){

case 1:
      bsort();
	  break;
case 2:
     ssort();
	 break;
case 3:
      isort();
	  break;
case 4:
      break;

}

}
while(choice!=4);
}
void display(int arr[],int n)
{
   for(int i=0;i<n;i++)
  {
       printf(" %d ",arr[i]);
  }
	printf("\n\n");
}


void bsort()
{
 int i,j,temp,arr[50],n;
 printf("Enter number of elements: ");
  scanf("%d",&n);
    printf("Enter the elements : ");
  for(i=0;i<n;i++)
  {
       scanf("%d",&arr[i]);
  }
 for(i=0;i<n;i++)
 {
     for(j=0;j<n-i-1;j++)
     {
         if(arr[j]>arr[j+1])
         {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
         }
     }
 }
printf("sorted array using Bubble sort is: ");
display(arr,n);
}

void ssort()
{
   int i,j,temp,n,arr[50];
   printf("Enter number of elements: ");
  scanf("%d",&n);
    printf("Enter the elements fo the array: ");
  for(i=0;i<n;i++)
  {
       scanf("%d",&arr[i]);
  }
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(arr[i]>arr[j])
           {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
           }
       }

   }
printf("Sorted array using selection sort is: ");
display(arr,n);
}


void isort()
{
   int i,j,min,n,arr[50];
   printf("Enter number of elements: ");
  scanf("%d",&n);
    printf("Enter the elements : ");
  for(i=0;i<n;i++)
  {
       scanf("%d",&arr[i]);
  }
   for(i=1;i<n-1;i++)
   {
       min=arr[i];
       j=i-1;
       while(min<arr[j] && j>=0)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=min;
   }
printf("sorted array using insertion sort is: ");
display(arr,n);
}
