from collections import deque

def bfs(x, y, k):
    queue = deque()
    queue.append((x, y, k))
    visited = [[[False] * (k+1) for _ in range(W)] for _ in range(H)]
    visited[x][y][k] = True
    dx = [-1, 1, 0, 0, -2, -2, -1, -1, 1, 1, 2, 2]
    dy = [0, 0, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1]

    while queue:
        cx, cy, ck = queue.popleft()
        if cx == H-1 and cy == W-1:
            return visited[cx][cy][ck] - 1
        
        for i in range(12):
            if i < 4:
                nx, ny = cx + dx[i], cy + dy[i]
                nk = ck
            else:
                nx, ny = cx + dx[i], cy + dy[i]
                nk = ck - 1
                
            if 0 <= nx < H and 0 <= ny < W and not visited[nx][ny][nk] and maze[nx][ny] != 1:
                visited[nx][ny][nk] = visited[cx][cy][ck] + 1
                queue.append((nx, ny, nk))
    return -1

K = int(input())
W, H = map(int, input().split())
maze = [list(map(int, input().split())) for _ in range(H)]

print(bfs(0, 0, K))
