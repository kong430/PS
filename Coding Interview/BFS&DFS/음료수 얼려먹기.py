n, m = map(int, input().split())

nmap = []
visited = [[False] * m for i in range(n)]

for i in range(n):
    nmap.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y):
    global visited
    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (nx < n and nx >= 0 and ny < m and ny >= 0) and not visited[nx][ny] and nmap[nx][ny] == 0:
            dfs(nx, ny)

cnt = 0 
for i in range(n):
    for j in range(m):
        if nmap[i][j] == 0 and not visited[i][j]:
            dfs(i, j)
            cnt += 1
            
print(cnt)
