# stock_prices=[]
# with open("C:\Internal_Folders\Dsa\Dsa\hashmap\stock_prices.csv") as f:
#     for line in f:
#         tokens=line.split(',')
#         day=tokens[0]
#         price=tokens[1]
#         stock_prices.append([day,price])
#         print(tokens)


# stock_prices={}
# with open("C:/Internal_Folders/Dsa/Dsa/hashmap/stock_prices.csv","r") as f:
#     for line in f:
#         tokens=line.strip().split(',')
#         day=tokens[0]
#         price=tokens[1]
#         stock_prices[day]=price
# print(stock_prices)

#Implementing hash table in python 

class HashTable:
    def __init__(self):
        self.MAX=100
        self.arr=[None for i in range(self.MAX)]
        
    def get_hash(self,key):
        h=0
        for char in key:
            h+=ord(char) #ord function gives the ascii value
        return h % self.MAX
    def __setitem__(self,key,value): # these are python inbuilt dictionary functio setitem and get item
        h=self.get_hash(key)
        self.arr[h]=value
    def __getitem__(self,key): # in this way we implemented dictionary internally
        h=self.get_hash(key)
        return self.arr[h]
    def __delitem__(self,key):
        h=self.get_hash(key)
        self.arr[h]=None
        
        
        

t=HashTable()
hashed=t.get_hash('march 6')
print(hashed)
# t.insert_val('march 6',302)
# t.insert_val('march 7',305)
t['march 6']=302
t['march 7']=305
print(t.arr)
print(t['march 6'])
print(t['march 7'])
del t['march 6']
print(t.arr)