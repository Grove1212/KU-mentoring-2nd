from collections import deque

def bfs(r,c,d):
    global arr
    global vx,vy
    flag=0
    count=0

    arr[r][c]=2
    count+=1
    q=deque()
    q.append([r,c])
    while q:
        a,b=q.popleft()
        for i in ((d+3)%4,(d+2)%4,(d+1)%4,d):
            x,y=a+vx[i],b+vy[i]
            if arr[x][y]==0:
                arr[x][y]=2
                count+=1
                q.append([x,y])
                d=i
            else:
                flag+=1
        if flag==4:
            ci,cj=a-vx[d],b-vy[d]
            if arr[ci][cj]==1:
                return count
            else:
                q.append([ci,cj])
            
            

N,M=map(int,input().split())
r,c,d = map(int,input().split())
arr=[]

vx=[-1,0,1,0]
vy=[0,1,0,-1]


for _ in range(N):
    arr.append(list(map(int, input().split())))

print(bfs(r,c,d))
