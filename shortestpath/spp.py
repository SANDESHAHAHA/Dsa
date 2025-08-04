import math
from heapdict import heapdict

G={
    's':{'t':10,'y':5},
    't':{'x':1,'y':2},
    'x':{'z':4},
    'y':{'t':3,'x':9,'z':2,},
    'z':{'s':7,'x':6}
    
} 

def DJ(G,s):
    cost={}
    prev={}
    for vertex in G.keys():
        cost[vertex]=math.inf
        prev[vertex]=" "
    cost[s]=0
    visited=list() #keep track of visited vertices
    PQ=heapdict()
    for vertex in G.keys():
        PQ[vertex]=cost[vertex] #shorted dictinary
    #Repeat until all the vertices are visitieid 
    while(len(visited)!=len(G.keys())):
        currentVertex,_=PQ.popitem()
        visited.append(currentVertex) #Add currentvertex  to visited
        for chimeki in G[currentVertex].keys():
            if chimeki not in visited:
                if cost[chimeki]>cost[currentVertex]+G[currentVertex][chimeki]:
                    cost[chimeki]=cost[currentVertex]+G[currentVertex][chimeki]
                    prev[chimeki]=currentVertex
                    PQ[chimeki]=cost[chimeki]
                    
    return cost,prev
def reconstruct_path(prev,vertex):
    path=vertex
    while prev[vertex]!=" ":
        path=prev[vertex]+'->'+path
        vertex=prev[vertex]
    return path
        
source='s'
cost,prev=DJ(G,source)
print(cost)
print(prev)
for vertex in G.keys():
    print(f"From {source} to {vertex} , path is {reconstruct_path(prev,vertex)}")
    print(f"Cost is {cost[vertex]}")

