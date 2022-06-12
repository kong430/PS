from collections import deque

n, m = map(int, input().split())

nmap = []
for i in range(n):
    nmap.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    q = deque()
    q.append((x, y))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # nmap 영역 벗어나는 경우 패스
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            # 벽일 경우 패스
            if nmap[nx][ny] == 0:
                continue
            # 처음 방문하는 노드일 경우
            if nmap[nx][ny] == 1:
                nmap[nx][ny] = nmap[x][y] + 1
                q.append((nx, ny))
    return nmap[n-1][m-1]
            
print(bfs(0, 0))
