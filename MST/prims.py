
G={
    'v1':{'v2':1,'v4':4},
    'v2':{'v1':1,'v3':3,'v5':3},
    'v3':{'v2':3,'v5':1,'v6':2},
    'v4':{'v1':4,'v5':1},
    'v5':{'v2':3,'v3':1,'v6':4,'v4':1},
    'v6':{'v5':4,'v3':2}
}

def Prims(G,vertex):
    visited=[start]
    mst=[]
    while len(visited)<len(G):
        min_weight=float('inf')
        min_edge=None
        for x in visited:
        
            for k,v in G[x].items():
                if k not in visited and v<min_weight:
                    min_weight=v
                    min_edge=(x,k)
        if min_edge is None :
            break
        v1,v2=min_edge
        mst.append(min_edge)
        visited.append(v2)
    return mst

start='v1'
output=Prims(G,start)
print(output)