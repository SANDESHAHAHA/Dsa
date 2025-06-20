//sum of n natural numbers 
#include<stdio.h>
#include<conio.h>
long int sum(int n,long int a){
    if (n==0){
        return a;
    }
    else{
return sum(n-1,a+n);
    } 
}
int main(){
    int n;
    printf("Enter for nth numbered natural sum: \n");
    scanf("%d",&n);
    printf("The sum of nth natural number is: %ld",sum(n,0));
    return 0;

}