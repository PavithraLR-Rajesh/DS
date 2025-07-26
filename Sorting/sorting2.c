/*This program implements merge sort (divide and conquer), quick sort (pivot-based partitioning), and
 heap sort (binary heap structure) to sort arrays efficiently*/
#include<stdio.h>
void mainmerge();
void mainquick();
void mainheapsort();
void mergesort(int ar[],int low,int up);
void merge(int ar[],int temp[],int low1,int up1,int low2,int up2);
void copy(int ar[],int temp[],int low1,int up1);
void quicksort(int arr[],int low,int up);
int partition(int ar[],int low,int up);
void heapsort(int a[],int N);
void percdown(int a[],int i,int n);
void swap(int a[],int i,int j);

void main() {
    int c,a;
    do {
        printf("Enter  1 for merge sort, 2 for quick sort, 3 for heap sort: ");
        scanf("%d",&c);
        switch(c) {
            case 1:
                mainmerge();
                break;
            case 2:
                mainquick();
                break;
            case 3:
                mainheapsort();
                break;
        }
        printf("\nDo you want to continue? Enter 1 for yes, 2 for no: ");
        scanf("%d",&a);
    } while(a==1);
}

void mainmerge() {
    int ar[50],i,j,n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&ar[i]);
    }
    mergesort(ar,0,n-1);
    for(i=0;i<n;i++) {
        printf("%d\t",ar[i]);
    }
}

void mergesort(int ar[],int low,int up) {
    int temp[50];
    int mid;
    if(low<up) {
        mid=(low+up)/2;
        mergesort(ar,low,mid);
        mergesort(ar,mid+1,up);
        merge(ar,temp,low,mid,mid+1,up);
        copy(ar,temp,low,up);
    }
}

void merge(int ar[],int temp[],int low1,int up1,int low2,int up2) {
    int i=low1;
    int j=low2;
    int k=low1;
    while((i<=up1)&&(j<=up2)) {
        if(ar[i]<=ar[j]) {
            temp[k++]=ar[i++];
        } else {
            temp[k++]=ar[j++];
        }
    }
    while(i<=up1) {
        temp[k++]=ar[i++];
    }
    while(j<=up2) {
        temp[k++]=ar[j++];
    }
}

void copy(int ar[],int temp[],int low,int up) {
    for(int i=low;i<=up;i++) {
        ar[i]=temp[i];
    }
}

void mainquick() {
    int ar[50],i,n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&ar[i]);
    }
    quicksort(ar,0,n-1);
    for(i=0;i<n;i++) {
        printf("%d\t",ar[i]);
    }
}

void quicksort(int arr[],int low,int up) {
    int partlc;
    if(low>=up)
        return;
    partlc=partition(arr,low,up);
    quicksort(arr,low,partlc-1);
    quicksort(arr,partlc+1,up);
}

int partition(int ar[],int low,int up) {
    int part,temp;
    int i=low+1;
    int j=up;
    part=ar[low];
    while(i<=j) {
        while(ar[i]<part&&low<up)
            i++;
        while(ar[j]>part)
            j--;
        if(i<j) {
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
        } else {
            i++;
        }
    }
    ar[low]=ar[j];
    ar[j]=part;
    return j;
}

void mainheapsort() {
    int ar[50],i,j,n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&ar[i]);
    }
    heapsort(ar,n);
    for(i=0;i<n;i++) {
        printf("%d\t",ar[i]);
    }
}

void heapsort(int a[],int N) {
    for(int i=N/2;i>=1;;i--) {
        percdown(a,i,N);
    }
    for(int i=N;i>=2;i--) {
        swap(a,1,i);
        percdown(a,1,i-1);
    }
}

void heapsort(int a[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        percdown(a, i, N);
    }
    for (int i = N - 1; i > 0; i--) {
        swap(a, 0, i);
        percdown(a, 0, i);
    }
}

void percdown(int a[], int i, int n) {
    int child;
    int temp = a[i];
    for (; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child + 1 < n && a[child + 1] > a[child])
            child++;
        if (temp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = temp;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
