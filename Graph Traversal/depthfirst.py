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
def DFS(G,start):
    stack=[]
    visited=[]
    stack.append(start)
    while(stack):
        popped_element=stack.pop()
        visited.append(popped_element)
        for adjacent in G[popped_element]:
            if adjacent not in stack and adjacent not in visited:
                stack.append(adjacent)
    return visited
output=DFS(G,'A')
print(output)
    
