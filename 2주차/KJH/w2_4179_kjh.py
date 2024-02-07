from collections import deque


fire = deque()
n, m = map(int, input().split())
for i in range(n):
    arr.append(list(input().strip()))
    for j in range(m):
        if arr[i][j] == 'J':
            arr[i][j] = '.'
            start = (i, j)
        elif arr[i][j] == 'F':
            fire.append((i, j))
arr = []
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
def solve():
    i, j = start
    visit = [[0] * m for _ in range(n)]
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    while q:
        
