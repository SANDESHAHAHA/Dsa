#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

void max_heapify(int A[],int i, int n)
{
    int l,r,largest;
    int temp;
    l=2*i;
    r=2*i+1;
    largest=i;

    if(l<=n && A[l]>A[largest])
    {
        largest=l;
    }
    if(r<=n && A[r]>A[largest])
    {
        largest=r;
    }
    if(i!=largest){
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;

        max_heapify(A,largest,n);
        
    }
}

void build_max_heap(int A[], int n)
{
    int i ;
    for(i=n/2; i>=1;i--)
    {
        max_heapify(A,i,n);
    }
}
void heap_sort(int A[],int n)
{
    int i , temp;
    build_max_heap(A,n);
    for(i=n;i>=2;i--){
        temp=A[i];
        A[i]=A[1];
        A[1]=temp;
        n=n-1;
        max_heapify(A,1,n);
    }
}
void display(int A[],int n){

    int i;
    for(i=1;i<=n;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n");
}
int main(){
    int i,n,A[MAX];

    clock_t start , end;
    double time_taken;

    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        A[i]=rand()%100;
    }
    display(A,n);
    start=clock();
    heap_sort(A,n);
    end=clock();
    display(A,n);
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken is %lf ",time_taken);
    return 0;
}