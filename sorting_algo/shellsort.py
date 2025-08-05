import random 

def shellsort(data):
    l=len(data)
    gap=l//2
    while gap>0:
        for i in range(gap,l):
            temp=data[i]
            j=i
            while (j>=gap and data[j-gap]>temp):
                data[j]=data[j-gap]
                j=j-gap
                
            data[j]=temp
        gap//=2
def display(data):
    print(*data)
n=int(input("Enter the number of the elements: "))
data=[random.randint(0,100) for _ in range(n)]  
display(data)
shellsort(data)
print("The shorted data is : ")
display(data)
         