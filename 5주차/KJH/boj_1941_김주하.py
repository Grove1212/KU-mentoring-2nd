from itertools import combinations

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def dfs(x, y, visited):
    visited[x][y] = True
    count = 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < 5 and 0 <= ny < 5 and not visited[nx][ny]:
            count += dfs(nx, ny, visited)

    return count

def find_combinations():
    result = 0
    for combination in combinations(range(25), 7):
        countS = 0
        visited = [[False] * 5 for _ in range(5)]

        for idx in combination:
            x, y = idx // 5, idx % 5
            if grid[x][y] == 'S':
                countS += 1
            visited[x][y] = True

        if countS >= 4:
            if dfs(x, y, visited) == 7:
                result += 1

    return result

grid = [input().strip() for _ in range(5)]
print(find_combinations())
