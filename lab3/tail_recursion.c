#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

long long int tailFact(int n,long long int a){
if(n<=1){
    return a;
}
    else {
        return tailFact(n-1,a*n);
    }
}
int main(){
    int fact;
    long long int ans;
    printf("Enter the number for calculating factoiral: \n");
    scanf("%d",&fact);
    ans=tailFact(fact,1);
    printf("The factorial of %d is %lld",fact,ans);
}