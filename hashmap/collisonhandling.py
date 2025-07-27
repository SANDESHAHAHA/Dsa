"""
Suppose your has function generated the index 9 
for march 6 and the same index is generated 9 for march 17 by the
given hash function now how to handle it ? 
This causes the collision . 

WE WIIL COME WITH THE CONCEPT OF CHAINING I.E. A LINKED LIST INTRODUCED
WHERE SAME KEY CAN HAVE MULTIPLE SAME VALUES .

The big O may go to bigO(n) for worst case scenarios .
"""

class HashTable:
    def __init__(self):
        self.MAX=100
        self.arr=[None for i in range(self.MAX)]

    def gethash(self,key):
        h=0
        for char in key:
            h+=ord(char)
        return h%self.MAX
    def __setitem__(self,key,value):
        h=self.gethash(key)
        
        if self.arr[h] is None:
            self.arr[h]=[(key,value)]
       
        else:  
                self.arr[h].append((key,value))  
                return
        
    def __getitem__(self,key):
        h=self.gethash(key)
        if self.arr[h] is not None:
            return [v for k, v in self.arr[h] if k==key]
        raise KeyError(f"{key} not found ")
    
    def __delitem__(self,key):
        h=self.gethash(key)
        self.arr[h]=None

t=HashTable()
t['march 6']=30
t['march 9']=200
t['march 4']=400 
t['march 9']=234
print(t['march 4'])
print(t['march 9'])
   
print(t.arr)


        
