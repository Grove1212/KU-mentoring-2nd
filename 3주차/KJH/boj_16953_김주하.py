a,b=map(int,input().split())
count=1
while(True):
    if a==b:
        print(count)
        exit(0)
    elif b<a:
        print('-1')
        exit(0)
    elif b%2==0:
        b//=2
        count+=1
    elif b%10==1:
        b//=10
        count+=1
    else:
        print('-1')
        exit(0)


