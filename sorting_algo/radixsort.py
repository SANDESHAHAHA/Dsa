import random 
def radixsort(data):
    radixarray=[[] for _ in range(10)]
    max_value=max(data)
    length=len(str(max_value))
    divisor=1
    start=1
    while start <= length:
        
        for number in data:
            index=(number//divisor)%10
            radixarray[index].append(number)
        data.clear()
        for innerarray in radixarray:
            while innerarray:
                data.append(innerarray.pop(0))
        
        start+=1
        divisor*=10
def display(data):
    print(*data)
            
n=int(input("Enter the number of data: "))
data=[random.randint(0,100) for _ in range(n)]
display(data)
print("\n")
radixsort(data)
display(data)
