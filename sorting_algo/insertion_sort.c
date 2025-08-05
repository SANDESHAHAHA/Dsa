#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000 

void insertion_sort(int A[], int n){
    int i ,j ,temp;
    for (i=0; i<n; i++){
        temp=A[i];
        j=i-1;
        while(j>=0 && temp<A[j]){
         A[j+1]=A[j];
         j=j-1;

        }
        A[j+1]=temp;
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
    int i,n,A[MAX];

    clock_t start,end;
    double time_taken;

    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        A[i]=rand()%100;
    }
    display(A,n);
    start=clock();
    insertion_sort(A,n);
    end=clock();
    display(A,n);
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken is : %lf",time_taken);
    return 0;

}
