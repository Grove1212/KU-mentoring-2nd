def dfs(n):
    print(n,end=' ')
    check[n]=True

    for i in range(1,N+1):
        if not check[i] and chart[n][i]:
            dfs(i)

def bfs():
    while(stack):
        cur=stack.pop(0)
        print(cur,end=' ')
        for i in range(1,N+1):
            if not check[i] and chart[cur][i]:
                check[i]=True
                stack.append(i)
    
N,M,V=map(int,input().split())
chart=[[False] * (N+1) for _ in range(N+1)]
check=[False]*(N+1)

for _ in range(M):
    a,b=map(int,input().split())
    chart[a][b]=True
    chart[b][a]=True

dfs(V)
print()

check=[False] * (N+1)
stack=[V]
check[V]=True
bfs()
