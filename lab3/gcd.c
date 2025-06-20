#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int a,b;
    printf("Enter two numbers for calculating gcd: \n");
    scanf("%d%d",&a,&b);
    int result=gcd(a,b);
    printf("The gcd of two numbers is : %d",result);
    return 0;
}