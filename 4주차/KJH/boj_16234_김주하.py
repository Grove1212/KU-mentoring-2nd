from collections import deque

def is_all_equal(arr):
    unique_elements = set()
    for row in arr:
        unique_elements.update(row)
    return len(unique_elements) == 1

def bfs():
    global L,R
    global arr,visited
    global dx,dy

    cnt=1
    hap=0
    q=deque()
    q.append([0,0])
    visited[0][0]=1
    
    while q:
        a,b=q.popleft()

        for d in range(4):
            nx,ny=a+dx[d],b+dy[d]
            if 0<=nx<N and 0<=ny<N and visited[nx][ny]==0:
                if L<=abs(arr[nx][ny]-arr[a][b])<=R:
                    cnt+=1        
                    visited[nx][ny]=1
                    q.append([nx,ny])
    for i in range(N):
        for j in range(N):
            if visited[i][j]==1:
                hap+=arr[i][j]
    for i in range(N):
        for j in range(N):
            if visited[i][j]==1:
                arr[i][j]=int(hap/cnt)

    return int(hap/cnt)
    

N,L,R=map(int,input().split())
arr=[]
for _ in range(N):
    arr.append(list(map(int,input().split())))
visited=[[0]*N for _ in range(N)]

dx=[0,0,-1,1]
dy=[1,-1,0,0]
count=0
bfs()
print(arr)
bfs()
print(arr)

while True:
    if is_all_equal(arr):
        print(count)
        exit(0)
    else:
        for i in range(N):
            for j in range(N):
                visited[i][j]=0
        bfs()
        count+=1
