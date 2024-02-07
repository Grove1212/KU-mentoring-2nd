def dfs(cur,hap):
    global ans
    if cur>=n:
        ans=max(hap,ans)
        return
    print(ans)
    if cur+T[cur]<=n:
        dfs(cur+T[cur],hap+P[cur])
    dfs(cur+1,hap)
        
n=int(input())
T=[0]*n
P=[0]*n

for i in range(n):
    T[i],P[i]=map(int,input().split())

ans=0
dfs(0,0)
print(ans)
