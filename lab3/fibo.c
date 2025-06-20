#include <stdio.h>
#include <conio.h>
long int table[100] = {0};

long int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0)
        {
            table[n] = fibo(n - 1) + fibo(n - 2);
        }
        return table[n];
    }
}
int main(){
    int num;
    printf("Enter the nth number: \n");
    scanf("%d",&num);
    long int result=fibo(num);
    printf("The result of %dth fibonacci number is %ld",num,result);
    return 0;
}