#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int partition(int A[],int l, int r){
    int x, y, pivot,temp;
    x=l;
    y=r;
    pivot=A[l];
    while(x<y)
    {
        while(A[x]<=pivot && x<=r) 
        x++;

        while(A[y]>pivot) y--;

        if(x<y) {
            temp=A[x];
            A[x]=A[y];
            A[y]=temp;

        }
    }
    temp=A[l];
    A[l]=A[y];
    A[y]=temp;
    return y;
}

void quicksort(int A[], int l, int r)
{
    int p;
    if(l<r)
    {
        p=partition(A,l,r);
        quicksort(A,l,p-1);
        quicksort(A,p+1,r);
  
    }
}

void display(int A[],int n ){
    int i;
    for(i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int i,n, A[MAX];
    clock_t start,end;
    double time_taken;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        A[i]=rand()%100;
    }
    display(A,n);
    start=clock();
    quicksort(A,0,n-1);
    end=clock();
    display(A,n);
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken is %lf ",time_taken);
    return 0;
}
