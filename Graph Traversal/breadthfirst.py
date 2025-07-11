G={
    'A':['B','C'],
    'B':['A','D','E'],
    'C':['A','F'],
    'D':['B','G'],
    'E':['B','H'],
    'F':['C'],
    'G':['D'],
    'H':['E']
}
start='A'
def BFS(G,start):
    queue=[]
    visited=[]
    queue.append(start)
    while(queue):
        popped_element=queue.pop(0)
        visited.append(popped_element)
        for adjacent in G[popped_element]:
            if adjacent not in queue and adjacent not in visited:
                queue.append(adjacent)
    return visited
output=BFS(G,'A')
print(output)
    