import random
queue=[]
def enqueue(elements):
    for item in elements:
        queue.append(item)
        
def display():
    print(*queue)
def dequeue():
    while queue:
        x=queue.pop(0)
        print(f"The popped item is {x}")
n=int(input("Enter the number of elements: "))
elements=[random.randint(0,100) for _ in range(n)]
enqueue(elements)
display()
dequeue()
