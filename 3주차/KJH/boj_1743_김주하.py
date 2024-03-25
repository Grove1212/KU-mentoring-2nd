from collections import deque

def bfs(i,j):
    global arr
    global dx,dy
    q=deque([[i,j]])
    arr[i][j]=2
    hap=1
    
    while q:
        x,y=q.popleft()
        for d in range(4):
            nx,ny=x+dx[d],y+dy[d]
            if 0<nx<=N and 0<ny<=M and arr[nx][ny]==1:
                q.append([nx,ny])
                arr[nx][ny]=2
                hap+=1             
                 
    return hap

N,M,K=map(int,input().split())

arr=[[0]*(M+1) for _ in range(N+1)]

dx=[0,0,-1,1]
dy=[-1,1,0,0]

for _ in range(K):
    x,y=map(int,input().split())
    arr[x][y]=1

compare=0
for i in range(1,N+1):
    for j in range(1,M+1):
        if arr[i][j]==1:
            ans=bfs(i,j)
            compare=max(ans,compare)
print(compare)
