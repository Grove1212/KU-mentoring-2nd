n=int(input())

d = [0] * (n+1)

d[1]=0

for i in range(2,n+1):
    d[i]=d[i-1]+1

    if i % 2 == 0:
        temp = d[i//2] + 1 #d[i]를 2로 나누었을때 얼마가 걸리나
        if temp<d[i]: # d[i]에서 1을 뺐을때와 2로 나누었을때 둘중 어느게 더 효율적인가
            d[i]=temp

    if i % 3 == 0:
        temp = d[i//3] + 1
        if temp < d[i]:
            d[i]=temp
print(d[n])
    
