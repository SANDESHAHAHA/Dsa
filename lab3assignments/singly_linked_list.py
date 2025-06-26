class Node:
    def __init__(self,data=None,next=None):
        self.data=data
        self.next=next
class LinkedList:
    def __init__(self):
        self.head=None
    
    def insert_at_beginning(self,data):
        node=Node(data,self.head)
        self.head=node
    def insert_at_end(self,data):
        if self.head is None:
            self.head=Node(data,None)
        itr=self.head
        while itr.next:
            itr=itr.next
        itr.next=Node(data,None)
    def insert_at_sp(self,data,pos):
        if pos<=0 :
            print("Invalid position")
            return
        elif pos==1: self.insert_at_beginning(data)
        else: 
            itr=self.head
            count=1
            while count<pos-1 and itr.next is not None:
                itr=itr.next
                count+=1 

            if(itr.next==None):
                self.insert_at_end(data)
            else:
                node=Node(data,itr.next)
                itr.next=node
    def del_at_beg(self):
        if self.head is None:
            print("No  list exists")
            return 
        else: 
           print(f"{self.head.data} is going to be deleted")
           self.head=self.head.next
    def del_at_end(self):
        if self.head is None:
            print("No list exists !")
            return
        elif self.head.next is None:
            print(f"{self.head.data} is going to be delted")
            self.head=None
        else: 
            itr=self.head 
            while itr.next.next is not None:
                itr=itr.next
            print(f"{itr.next.data} is going to be deleted .")
            itr.next=None
            
    def del_at_sp(self,pos):
        if self.head==None:
            print("No list exists for deletion.")
            return 
        elif self.head.next==None:
            print(f"{self.head.data} is going to be deleted")
            self.del_at_beg()
        else: 
            itr=self.head
            count=1
            while count<pos-1 and itr.next is not None:
                itr=itr.next
            print(f"{itr.next.data} is going to be deleted.")
            self.head.next=self.head.next.next

    def print(self):
        if self.head is None:
            print("List is empty.")
            return 
        itr=self.head
        liststr=''
        while itr:
            liststr+=str(itr.data)+'-->'
            itr=itr.next
        print(liststr)
ll=LinkedList()
ll.insert_at_beginning(20)
ll.print()
ll.insert_at_beginning(30)
ll.print()
ll.insert_at_end(90)
ll.print()
ll.insert_at_sp(34,1)
ll.print()
ll.insert_at_sp(43,4)
ll.print()
ll.insert_at_sp(1000,1000)
ll.print()
ll.del_at_beg()
ll.print()
ll.del_at_end()
ll.print()
ll.del_at_sp(2)
ll.print()