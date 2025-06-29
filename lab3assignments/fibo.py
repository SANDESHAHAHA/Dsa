def fibo(n,table=None): # table={} acts as an mutable argument or overwrriten by a new dictionary calls and takes more space ! 
    if table is None:
        table={} 
        
    if n==1 or n==2:
        return 1
    if n in table:
        return table[n]
    table[n]=fibo(n-1,table)+fibo(n-2,table)
    return table[n]
        

n=int(input("Enter the nth term to calculate the fibonacci series: "))
result =fibo(n)
print(f"The nth fibonacci term is {result}")

#The defualt max recurrsion availale is 1000 calls ! 

#The memoization works like this while using a dictionary , if you ever wonder how the above code works you can run this below code hehe

# table={3:'hi'}
# print(table[3])
# table[4]="mi "  
# print(table)
# print(table[4])


