class Node:
    def __init__(self,coeff,power):
        self.coeff=coeff
        self.power=power
        self.next=None

class Polynomial:
    def __init__(self):
        self.head=None
    
    def insert_term(self,coeff,power):
        if self.head is None:
            self.head=Node(coeff,power)
        else:
            itr=self.head
            while itr.next:
                itr=itr.next
            itr.next=Node(coeff,power)
     
    def display(self):
        terms=[]
        if self.head is None: 
            print("Empty ! ")
        current=self.head
        while current:
            print(f"{current.coeff}x^{current.power}",end='')
            if current.next:
                print("+",end='')
            current=current.next
        print("\n")
            
    def evaluate(self,x):
        result=0
        temp=self.head
        while temp:
            result+=temp.coeff*(x**temp.power)
            temp=temp.next
        return result
poly=Polynomial()
poly.insert_term(3,3)
poly.insert_term(5,2)
poly.insert_term(-6,1)
poly.insert_term(2,0)
print("Polynomial: ")
poly.display()

n=int(input("Enter the value for calculating the polynomial : "))
print(f"The value of polynomial at x={n} is {poly.evaluate(n)}")
