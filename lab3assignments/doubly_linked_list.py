class Node:
    def __init__(self,data,next=None,prev=None):
        self.data=data
        self.next=next
        self.prev=prev
class DoublyLinkedList:
    def __init__(self):
        self.head=None

    def insert_at_beginning(self,data): 
            node=Node(data,self.head)
            if self.head is not None:
                self.head.prev=node
            self.head=node
            
    def insert_at_end(self,data):
        if self.head is None:
              self.insert_at_beginning(data)
        else:
            itr=self.head
            while itr.next: 
                itr=itr.next
            itr.next=Node(data,None,itr)
            itr.next.prev=itr
    def insert_at_sp(self,data,pos):
        if pos<=0:
            print("Invalid position for insertion of element !")
            return
        elif pos==1:
             self.insert_at_beginning(data)
        else:
            itr=self.head
            count=1
            while count<pos-1 and itr.next is not None:
                itr=itr.next
                count+=1
            if itr.next==None:
                self.insert_at_end(data)
            else:
                node=Node(data,itr.next,itr)
                itr.next=node
                if node.next is not None:
                  node.next.prev=node
    def del_at_beginning(self):
        if self.head is None:
            print("No elements to perform deletion !")
            return 
        elif self.head.next is None:
            print(f"{self.head.data} is going to be deleted")
            self.head=None
        else :
            print(f"{self.head.data} is going to be deleted! ")
            self.head=self.head.next
            self.head.prev=None
    def del_at_end(self):
        if self.head is None:
            print("No elements to perform deletion !")
            return 
        elif self.head.next is None:
            self.del_at_beginning()
        else:
            itr=self.head
            while itr.next.next is not None:
                itr=itr.next
            print(f"{itr.next.data} is going to be deleted!")
            itr.next.prev=None
            itr.next=None
    def del_at_sp(self,pos):
        if self.head is None:
            print("No elements for deletion !")
            return 
        else: 
            if pos<=0:
                print("Invalid postional argument !")
                return
            elif pos==1:
                self.del_at_beginning()
                return
            itr=self.head
            count=1
            while count<pos-1 and itr.next is not None:
                itr=itr.next
                count+=1
            if itr.next==None:
                self.del_at_end()
            else:
                print(f"{itr.next.data} is going to be delted !") 
                itr.next.next.prev=itr
                itr.next=itr.next.next
                
    def print(self):
        if self.head is None:
            print("List is empty! ")
            return
        itr=self.head
        liststr=''
        while itr:
            liststr+=str(itr.data)+"-->"
            itr=itr.next
        print(liststr)
dll=DoublyLinkedList()
dll.insert_at_beginning(20)
dll.print()
dll.insert_at_beginning(30)
dll.print()
dll.insert_at_end(40)
dll.print()
dll.insert_at_end(50)
dll.print()
dll.insert_at_sp(100,2)
dll.print()
dll.insert_at_sp(200,3)
dll.print()
dll.del_at_beginning()
dll.print()
dll.del_at_end()
dll.print()
dll.del_at_sp(100)
dll.print()
dll.del_at_sp(2)
dll.print()
            
                
        
    
        
            
         