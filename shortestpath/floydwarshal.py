
W=[
    [0,10,0,5,0],
    [0,0,1,2,0],
    [0,0,0,0,4],
    [0,3,9,0,2],
    [7,0,6,0,0]
]
def FloydWarshall(W):
    n=len(W)
    D=dict()
    D[-1]=W
    for k in range(n):
        D[k]=D[k-1]
        for i in range(n):
            for j in range(n):
                 D[k][i][j]=min(D[k-1][i][j],D[k-1][i][j]+D[k-1][k][j])
        print(k)
        return D[k]
